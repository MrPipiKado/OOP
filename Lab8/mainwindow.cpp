#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"
#include "percentage.h"
#include "progresive.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_common_clicked()
{
    ui->tabWidget->addTab(new Common(), QString("Account"));

}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::on_percentage_clicked()
{
    ui->tabWidget->addTab(new Percentage(), QString("AccountPercentage"));
}

void MainWindow::on_progresive_clicked()
{
    ui->tabWidget->addTab(new Progresive(), QString("AccountProgressive"));
}
