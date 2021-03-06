#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <exception>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->input_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->input_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->input_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->input_1->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    try
    {
        loggingg("Program started");
    } catch (std::exception & ex)
    {
        exit(1);
    }
}

MainWindow::~MainWindow()
{
    try
    {
        loggingg("Program ended");
    } catch (std::exception & ex)
    {
        exit(1);
    }
    delete ui;
}

void MainWindow::on_set_1_clicked()
{
    try
    {
        ui->input_1->setRowCount(ui->rows_1->text().toInt());
        ui->input_1->setColumnCount(ui->colons_1->text().toInt());
        this->op1.set_size(ui->rows_1->text().toInt(), ui->colons_1->text().toInt());
    } catch (std::exception &ex)
    {
        try
        {
            loggingg(ex.what());
        } catch (std::exception & ex)
        {
            exit(1);
        }
        QMessageBox::information(this, "ERROR", QString(ex.what()));
    }

}

void MainWindow::on_set_2_clicked()
{
    try {
        ui->input_2->setRowCount(ui->rows_2->text().toInt());
        ui->input_2->setColumnCount(ui->colons_2->text().toInt());
        this->op2.set_size(ui->rows_2->text().toInt(), ui->colons_2->text().toInt());
    } catch (std::exception &ex)
    {
        try
        {
            loggingg(ex.what());
        } catch (std::exception & ex)
        {
            exit(1);
        }
        QMessageBox::information(this, "ERROR", QString(ex.what()));
    }

}

void MainWindow::on_enter_1_clicked()
{
    try {
        ui->input_1>>this->op1;
    } catch (std::exception &ex)
    {
        try
        {
            loggingg(ex.what());
        } catch (std::exception & ex)
        {
            exit(1);
        }
        QMessageBox::information(this, "ERROR", QString(ex.what()));
    }

}

void MainWindow::on_enter_2_clicked()
{
    try {
            ui->input_2>>this->op2;
    } catch (std::exception &ex)
    {
        try
        {
            loggingg(ex.what());
        } catch (std::exception & ex)
        {
            exit(1);
        }
        QMessageBox::information(this, "ERROR", QString(ex.what()));
    }

}

void MainWindow::on_add_clicked()
{
    try {
            res = op1 + op2;
    } catch (std::exception &ex)
    {
        try
        {
            loggingg(ex.what());
        } catch (std::exception & ex)
        {
            exit(1);
        }
        QMessageBox::information(this, "ERROR", QString(ex.what()));
    }
    ui->output<<res;
}

void MainWindow::on_mul_clicked()
{
    try {
            res = op1 * op2;
    } catch (std::exception &ex)
    {
        try
        {
            loggingg(ex.what());
        } catch (std::exception & ex)
        {
            exit(1);
        }
        QMessageBox::information(this, "ERROR", QString(ex.what()));
    }
    ui->output<<res;
}

void MainWindow::on_add_num_1_clicked()
{
    op1 += (ui->num_1->text().toDouble());
    ui->input_1<<op1;
}

void MainWindow::on_mil_num_1_clicked()
{
    op1 *= (ui->num_1->text().toDouble());
    ui->input_1<<op1;
}

void MainWindow::on_add_num_2_clicked()
{
    op2 += (ui->num_2->text().toDouble());
    ui->input_1<<op2;
}

void MainWindow::on_mul_num_2_clicked()
{
    op2 *= (ui->num_2->text().toDouble());
    ui->input_2<<op2;
}

void MainWindow::on_min_1_b_clicked()
{
    ui->min_1->setText(QString::number(op1.min()));
}

void MainWindow::on_min_2_b_clicked()
{
    ui->min_2->setText(QString::number(op2.min()));
}
