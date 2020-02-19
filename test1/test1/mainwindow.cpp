#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pbChange1, SIGNAL(clicked()), this, SLOT(change_healder()));
    connect(ui->pbChange, SIGNAL(clicked()), this, SLOT(change_healder()));
    connect(ui->pbEdit, SIGNAL(clicked()), this, SLOT(edit_healder()));
    ui->frame->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_healder()
{
    if(ui->frame->isVisible())
    {
        //ui->frame->setVisible(false);
        //ui->frame_2->setVisible(true);
        ui->frame->hide();
        ui->frame_2->show();
    }
    else
    {
        //ui->frame->setVisible(true);
        //ui->frame_2->setVisible(false);
        ui->frame_2->hide();
        ui->frame->show();
    }

}

void MainWindow::edit_healder()
{
    ui->label->setText(ui->lineEdit->text());
}
