#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    this->buffer.push_back(ui->label->text().toStdString());
    this->current  = this->buffer.begin();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actiontools_triggered()
{
    ui->lineEdit->setText(ui->label->text());
    this->buffer.push_back(ui->label->text().toStdString());
    ui->actionUndo->setEnabled(true);
    this->current+=1;
}

void MainWindow::on_actionKeep_triggered()
{
    ui->label->setText(ui->lineEdit->text());
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(ui->actiontools);
    menu.addAction(ui->actionKeep);
    menu.addAction(ui->actionUndo);
    menu.addAction(ui->actionRedo);
    menu.exec(QCursor::pos());
}


void MainWindow::on_actionUndo_triggered()
{
    this->current-=1;
    if(current==buffer.begin())
        ui->actionUndo->setEnabled(false);
    ui->label->setText(QString::fromStdString(*current));
    ui->actionRedo->setEnabled(true);
}

void MainWindow::on_actionRedo_triggered()
{
    this->current+=1;
    if(current==buffer.end())
        ui->actionRedo->setEnabled(false);
    ui->label->setText(QString::fromStdString(*current));
    ui->actionRedo->setEnabled(true);
}
