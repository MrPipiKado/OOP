#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionUndo->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actiontools_triggered()
{
    ui->lineEdit->setText(ui->label->text());
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

