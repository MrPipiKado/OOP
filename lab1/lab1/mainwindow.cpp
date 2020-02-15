#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(print_lable()));
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print_lable()
{
    this->ui->label->setText(this->ui->lineEdit->text());
}
