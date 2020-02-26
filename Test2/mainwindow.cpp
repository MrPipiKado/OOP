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
    ui->lineEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    this->current  = 0;
    this->buffer.push_back(ui->label->text().toStdString());
    ui->lineEdit->setVisible(false);
    ui->actionKeep->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actiontools_triggered()
{
    ui->lineEdit->setText(ui->label->text());
    ui->label->setVisible(false);
    ui->lineEdit->setVisible(true);
    ui->actiontools->setEnabled(false);
    ui->actionKeep->setEnabled(true);
}

void MainWindow::on_actionKeep_triggered()
{
    ui->label->setText(ui->lineEdit->text());
    this->buffer.push_back(ui->label->text().toStdString());
    ui->actionUndo->setEnabled(true);
    ui->label->setVisible(true);
    ui->lineEdit->setVisible(false);
    this->current+=1;
    ui->actionKeep->setEnabled(false);
    ui->actiontools->setEnabled(true);
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
    if(current==0)
        ui->actionUndo->setEnabled(false);
    ui->label->setText(QString::fromStdString(buffer[current]));
    ui->actionRedo->setEnabled(true);
}

void MainWindow::on_actionRedo_triggered()
{
    this->current+=1;
    if(current==buffer.size()-1)
        ui->actionRedo->setEnabled(false);
    ui->label->setText(QString::fromStdString(buffer[current]));
    ui->actionUndo->setEnabled(true);
}



void MainWindow::on_lineEdit_customContextMenuRequested(const QPoint &pos)
{
    QMenu menu(this);
    menu.addAction(ui->actiontools);
    menu.addAction(ui->actionKeep);
    menu.addAction(ui->actionUndo);
    menu.addAction(ui->actionRedo);
    menu.exec(QCursor::pos());
}
