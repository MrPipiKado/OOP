#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->input_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->input_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->input_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->input_1->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_set_1_clicked()
{
    ui->input_1->setRowCount(ui->rows_1->text().toInt());
    ui->input_1->setColumnCount(ui->colons_1->text().toInt());
    this->op1.set_size(ui->rows_1->text().toInt(), ui->colons_1->text().toInt());
}

void MainWindow::on_set_2_clicked()
{
    ui->input_2->setRowCount(ui->rows_2->text().toInt());
    ui->input_2->setColumnCount(ui->colons_2->text().toInt());
    this->op2.set_size(ui->rows_2->text().toInt(), ui->colons_2->text().toInt());
}

void MainWindow::on_enter_1_clicked()
{
    ui->input_1>>this->op1;
}

void MainWindow::on_enter_2_clicked()
{
    ui->input_2>>this->op2;
}

void MainWindow::on_add_clicked()
{
    res = op1 + op2;
    ui->output<<res;
}

void MainWindow::on_mul_clicked()
{
    res = op1 * op2;
    ui->output<<res;
}
