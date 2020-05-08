#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableA->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableA->setRowCount(1);
    ui->tableB->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableB->setRowCount(1);
    ui->tableC->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableC->setRowCount(1);
    ui->tableD->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableD->setRowCount(1);
    ui->tableA->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableB->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableC->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableD->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    A=B=nullptr;
    C=nullptr;
    D=nullptr;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spin_A_valueChanged(int arg1)
{
    ui->tableA->setColumnCount(arg1);
}

void MainWindow::on_spin_B_valueChanged(int arg1)
{
    ui->tableB->setColumnCount(arg1);
}

void MainWindow::on_set_A_clicked()
{
    delete A;
    A = new std::list<int>;
    for(int i = 0; i<ui->tableA->columnCount(); ++i)
    {
        A->push_back(ui->tableA->item(0, i)->text().toInt());
    }
}

void MainWindow::on_pushButton_clicked()
{
    A->remove(ui->remove->text().toInt());
    ui->tableA->clear();
    ui->tableA->setRowCount(1);
    ui->tableA->setColumnCount(0);
    ui->tableA->setColumnCount(A->size());
    int tmp = 0;
    for(auto i = A->begin();i!=A->end();++i, ++tmp)
    {
        ui->tableA->setItem(0, tmp, new QTableWidgetItem(QString::number(*i)));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    A->push_back(ui->add->text().toInt());
    ui->tableA->clear();
    ui->tableA->setRowCount(1);
    ui->tableA->setColumnCount(0);
    ui->tableA->setColumnCount(A->size());
    int tmp = 0;
    for(auto i = A->begin();i!=A->end();++i, ++tmp)
    {
        ui->tableA->setItem(0, tmp, new QTableWidgetItem(QString::number(*i)));
    }
}

void MainWindow::on_set_B_clicked()
{
    delete B;
    B = new std::list<int>;
    for(int i = 0; i<ui->tableB->columnCount(); ++i)
    {
        B->push_back(ui->tableB->item(0, i)->text().toInt());
    }
}

void MainWindow::on_insert_clicked()
{
    int tmp, tmp2;
    tmp = ui->from->text().toInt();--tmp;
    tmp2 = ui->n_n->text().toInt();
    auto begin = A->begin();
    std::advance(begin, tmp);
    auto n = begin;
    std::advance(n, tmp2);
    A->erase(begin, n);
    begin = A->begin();
    std::advance(begin, tmp);
    A->insert(begin, B->begin(), B->end());
    ui->tableA->clear();
    ui->tableA->setRowCount(1);
    ui->tableA->setColumnCount(0);
    ui->tableA->setColumnCount(A->size());
    tmp = 0;
    for(auto i = A->begin();i!=A->end();++i, ++tmp)
    {
        ui->tableA->setItem(0, tmp, new QTableWidgetItem(QString::number(*i)));
    }
}

bool com(const int& op1, const int& op2)
{
    return op1 > op2;
}

void MainWindow::on_sort_A_clicked()
{
    A->sort(com);
    ui->tableA->clear();
    ui->tableA->setRowCount(1);
    ui->tableA->setColumnCount(0);
    ui->tableA->setColumnCount(A->size());
    int tmp = 0;
    for(auto i = A->begin();i!=A->end();++i, ++tmp)
    {
        ui->tableA->setItem(0, tmp, new QTableWidgetItem(QString::number(*i)));
    }
}

bool is_odd (int i)
{
    return ((i%2)==1);
}

void MainWindow::on_pushButton_3_clicked()
{
    auto find = std::find_if(A->begin(), A->end(), is_odd);
    ui->odd->setText(QString::number(*find));
}

void MainWindow::on_fillC_clicked()
{
    delete C;
    C = new std::deque<int>;
    for(auto i:*A)
    {
        if(i%2)
        {
            C->push_back(i);
        }
    }
    ui->tableC->clear();
    ui->tableC->setRowCount(1);
    ui->tableC->setColumnCount(0);
    ui->tableC->setColumnCount(C->size());
    int tmp = 0;
    for(auto i = C->begin();i!=C->end();++i, ++tmp)
    {
        ui->tableC->setItem(0, tmp, new QTableWidgetItem(QString::number(*i)));
    }
}

void MainWindow::on_sort_A_2_clicked()
{
    A->sort();
    ui->tableA->clear();
    ui->tableA->setRowCount(1);
    ui->tableA->setColumnCount(0);
    ui->tableA->setColumnCount(A->size());
    int tmp = 0;
    for(auto i = A->begin();i!=A->end();++i, ++tmp)
    {
        ui->tableA->setItem(0, tmp, new QTableWidgetItem(QString::number(*i)));
    }
}

void MainWindow::on_sort_C_clicked()
{
    std::sort(C->begin(), C->end());
    ui->tableC->clear();
    ui->tableC->setRowCount(1);
    ui->tableC->setColumnCount(0);
    ui->tableC->setColumnCount(C->size());
    int tmp = 0;
    for(auto i = C->begin();i!=C->end();++i, ++tmp)
    {
        ui->tableC->setItem(0, tmp, new QTableWidgetItem(QString::number(*i)));
    }
}

void MainWindow::on_merge_clicked()
{
    delete D;
    D = new std::vector<int>;
    std::merge(A->begin(), A->end(),
                C->begin(), C->end(),
                std::back_inserter(*D));
    ui->tableD->clear();
    ui->tableD->setRowCount(1);
    ui->tableD->setColumnCount(0);
    ui->tableD->setColumnCount(D->size());
    int tmp = 0;
    for(auto i = D->begin();i!=D->end();++i, ++tmp)
    {
        ui->tableD->setItem(0, tmp, new QTableWidgetItem(QString::number(*i)));
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    int count = 0;
    for(auto i:*D)
    {
        if(i%2)
        {
            ++count;
        }
    }
    ui->odd_in_merget->setText(QString::number(count));
}
