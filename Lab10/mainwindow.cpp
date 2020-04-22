#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_a->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_a->setHorizontalHeaderItem(0, new QTableWidgetItem("Real"));
    ui->table_a->setHorizontalHeaderItem(1, new QTableWidgetItem("Imagine"));
    ui->table_b->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_b->setHorizontalHeaderItem(0, new QTableWidgetItem("Real"));
    ui->table_b->setHorizontalHeaderItem(1, new QTableWidgetItem("Imagine"));
    ui->result->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->result->setHorizontalHeaderItem(0, new QTableWidgetItem("Real"));
    ui->result->setHorizontalHeaderItem(1, new QTableWidgetItem("Imagine"));
    A = B = R = nullptr;
}

MainWindow::~MainWindow()
{
    delete A;
    delete B;
    delete R;
    delete ui;
}


void MainWindow::on_num_a_valueChanged(int arg1)
{
    ui->table_a->setRowCount(arg1);
}

void MainWindow::on_num_b_valueChanged(int arg1)
{
    ui->table_b->setRowCount(arg1);
}

void MainWindow::on_set_a_clicked()
{
    Complex tmp[ui->num_a->text().toInt()];
    for(int i = 0; i<ui->num_a->text().toInt(); ++i)
    {
        tmp[i] = Complex(ui->table_a->item(i, 0)->text().toInt(),
                         ui->table_a->item(i, 1)->text().toInt());
    }
    delete A;
    A = new SET::Set<Complex>(tmp, ui->num_a->text().toInt());
}

void MainWindow::on_set_b_clicked()
{
    Complex tmp[ui->num_b->text().toInt()];
    for(int i = 0; i<ui->num_b->text().toInt(); ++i)
    {
        tmp[i] = Complex(ui->table_b->item(i, 0)->text().toInt(),
                         ui->table_b->item(i, 1)->text().toInt());
    }
    delete B;
    B = new SET::Set<Complex>(tmp, ui->num_b->text().toInt());
}

void MainWindow::on_plus_clicked()
{
    delete R;
    R = new SET::Set<Complex>();
    *R = *A + *B;
    ui->result->clear();
    ui->result->setRowCount(0);
    ui->result->setColumnCount(0);
    ui->result->setColumnCount(2);
    ui->result->setHorizontalHeaderItem(0, new QTableWidgetItem("Surname"));
    ui->result->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    ui->result->setRowCount(R->get_size()+1);
    for(int i = 0; i<=R->get_size(); ++i)
    {
        ui->result->setItem(i, 0, new QTableWidgetItem((*R)[i].get_real()));
        ui->result->setItem(i, 1, new QTableWidgetItem((*R)[i].get_imag()));
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    delete R;
    R = new SET::Set<Complex>();
    *R = *A - *B;
    ui->result->setRowCount(R->get_size());
    ui->result->clear();
    ui->result->setRowCount(0);
    ui->result->setColumnCount(0);
    ui->result->setColumnCount(2);
    ui->result->setHorizontalHeaderItem(0, new QTableWidgetItem("Surname"));
    ui->result->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    ui->result->setRowCount(R->get_size());
    for(int i = 0; i<=R->get_size(); ++i)
    {
        ui->result->setItem(i, 0, new QTableWidgetItem((*R)[i].get_real()));
        ui->result->setItem(i, 1, new QTableWidgetItem((*R)[i].get_imag()));
    }
}

void MainWindow::on_div_clicked()
{
    delete R;
    R = new SET::Set<Complex>();
    *R = *A / *B;
    ui->result->clear();
    ui->result->setRowCount(0);
    ui->result->setColumnCount(0);
    ui->result->setColumnCount(2);
    ui->result->setHorizontalHeaderItem(0, new QTableWidgetItem("Surname"));
    ui->result->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    ui->result->setRowCount(R->get_size());
    for(int i = 0; i<R->get_size(); ++i)
    {
        ui->result->setItem(i, 0, new QTableWidgetItem((*R)[i].get_real()));
        ui->result->setItem(i, 1, new QTableWidgetItem((*R)[i].get_imag()));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    delete R;
    R = new SET::Set<Complex>();
    *R = *A ^ *B;
    ui->result->clear();
    ui->result->setRowCount(0);
    ui->result->setColumnCount(0);
    ui->result->setColumnCount(2);
    ui->result->setHorizontalHeaderItem(0, new QTableWidgetItem("Surname"));
    ui->result->setHorizontalHeaderItem(1, new QTableWidgetItem("Name"));
    ui->result->setRowCount(R->get_size());
    for(int i = 0; i<R->get_size(); ++i)
    {
        ui->result->setItem(i, 0, new QTableWidgetItem((*R)[i].get_real()));
        ui->result->setItem(i, 1, new QTableWidgetItem((*R)[i].get_imag()));
    }
}
