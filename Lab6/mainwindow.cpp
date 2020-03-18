#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "mycomplex.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->real_1->ID = 0;
    ui->real_2->ID = 0;
    ui->imagine_1->ID = 1;
    ui->imagine_2->ID = 1;
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_set_1_clicked()
{
    ui->real_1>>this->op1;
    ui->imagine_1>>this->op1;
    ui->op1_print<<this->op1;
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}
void MainWindow::on_set_2_clicked()
{
    ui->real_2>>this->op2;
    ui->imagine_2>>this->op2;
    ui->op2_print<<this->op2;
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_add_clicked()
{
    res = op1+op2;
    ui->res_print<<res;
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_sub_clicked()
{
    res = op1-op2;
    ui->res_print<<res;
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_mul_clicked()
{
    res = op1*op2;
    ui->res_print<<res;
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_div_clicked()
{
    res = op1/op2;
    ui->res_print<<res;
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_pow_1_clicked()
{
    res = op1^((ui->n_2->text()).toInt());
    ui->res_print<<res;
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_algebra_1_clicked()
{
    ui->op1_print->setText(QString::fromStdString("1)" + this->op1.get_algebra()));
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_trigono_1_clicked()
{
    ui->op1_print->setText(QString::fromStdString("1)" + this->op1.get_trigonometry()));
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_algebra_2_clicked()
{
    ui->op2_print->setText(QString::fromStdString("1)" + this->op2.get_algebra()));
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_trigonom_2_clicked()
{
    ui->op2_print->setText(QString::fromStdString("2)" + this->op2.get_trigonometry()));
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_algebrs_3_clicked()
{
    ui->res_print->setText(QString::fromStdString("2)" + this->res.get_algebra()));
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_trigonom_3_clicked()
{
    ui->res_print->setText(QString::fromStdString("res)" + this->res.get_trigonometry()));
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_root_1_clicked()
{
    res = op1.root((ui->n_1->text()).toInt());
    ui->res_print->setText(QString::fromStdString("1)" + this->res.get_algebra()));
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_pow_2_clicked()
{
    res = op2^((ui->n_2->text()).toInt());
    ui->res_print->setText(QString::fromStdString("2)" + this->res.get_algebra()));
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_root_2_clicked()
{
    res = op2.root((ui->n_2->text()).toInt());
    ui->res_print->setText(QString::fromStdString("2)" + this->res.get_algebra()));
    ui->statusbar->showMessage("Counter:" + QString::number(op1.get_count()));
}

void MainWindow::on_compare_clicked()
{
    if(op1<op2)
    {
        ui->show_compare->setText("1 < 2");
    }
    else if(op1>op2)
    {
        ui->show_compare->setText("1 > 2");
    }
    else if(op1==op2)
    {
        ui->show_compare->setText("1 == 2");
    }
}
