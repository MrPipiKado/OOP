#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "mycomplex.h"
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

void MainWindow::on_set_1_clicked()
{
    this->op1.set_real((ui->real_1->text()).toDouble());
    this->op1.set_imagine((ui->imagine_1->text()).toDouble());
    ui->op1_print->setText(QString::fromStdString("1)" + this->op1.get_algebra()));
}

void MainWindow::on_set_2_clicked()
{
    this->op2.set_real((ui->real_2->text()).toDouble());
    this->op2.set_imagine((ui->imagine_2->text()).toDouble());
    ui->op2_print->setText(QString::fromStdString("2)" + this->op2.get_algebra()));
}

void MainWindow::on_add_clicked()
{
    this->res.set_real(this->op1.get_real());
    this->res.set_imagine(this->op1.get_imagine());
    this->res.add(this->op2);
    ui->res_print->setText(QString::fromStdString("res)" + this->res.get_algebra()));
}

void MainWindow::on_sub_clicked()
{
    this->res.set_real(this->op1.get_real());
    this->res.set_imagine(this->op1.get_imagine());
    this->res.sub(this->op2);
    ui->res_print->setText(QString::fromStdString("res)" + this->res.get_algebra()));
}

void MainWindow::on_mul_clicked()
{
    this->res.set_real(this->op1.get_real());
    this->res.set_imagine(this->op1.get_imagine());
    this->res.mul(this->op2);
    ui->res_print->setText(QString::fromStdString("res)" + this->res.get_algebra()));
}

void MainWindow::on_div_clicked()
{
    this->res.set_real(this->op1.get_real());
    this->res.set_imagine(this->op1.get_imagine());
    this->res.div(this->op2);
    ui->res_print->setText(QString::fromStdString("res)" + this->res.get_algebra()));
}

void MainWindow::on_pow_1_clicked()
{
    this->op1.pow((ui->n_1->text()).toInt());
    ui->op1_print->setText(QString::fromStdString("1)" + this->op1.get_algebra()));
}

void MainWindow::on_algebra_1_clicked()
{
    ui->op1_print->setText(QString::fromStdString("1)" + this->op1.get_algebra()));
}

void MainWindow::on_trigono_1_clicked()
{
    ui->op1_print->setText(QString::fromStdString("1)" + this->op1.get_trigonometry()));
}

void MainWindow::on_algebra_2_clicked()
{
    ui->op2_print->setText(QString::fromStdString("1)" + this->op2.get_algebra()));
}

void MainWindow::on_trigonom_2_clicked()
{
    ui->op2_print->setText(QString::fromStdString("2)" + this->op2.get_trigonometry()));
}

void MainWindow::on_algebrs_3_clicked()
{
    ui->res_print->setText(QString::fromStdString("2)" + this->res.get_algebra()));
}

void MainWindow::on_trigonom_3_clicked()
{
    ui->res_print->setText(QString::fromStdString("res)" + this->res.get_trigonometry()));
}

void MainWindow::on_root_1_clicked()
{
    res = op1.root((ui->n_1->text()).toInt());
    ui->op1_print->setText(QString::fromStdString("1)" + this->res.get_algebra()));
}

void MainWindow::on_pow_2_clicked()
{
    this->op2.pow((ui->n_2->text()).toInt());
    ui->op2_print->setText(QString::fromStdString("2)" + this->op2.get_algebra()));
}

void MainWindow::on_root_2_clicked()
{
    res = op2.root((ui->n_2->text()).toInt());
    ui->op2_print->setText(QString::fromStdString("2)" + this->res.get_algebra()));
}
