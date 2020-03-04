#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#define NUM_AFTER_POINT 9
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    set_table();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_table()
{
    ui->tableWidget->setRowCount(ui->spinBox->text().toInt());
    ui->tableWidget->setColumnCount(ui->spinBox_2->text().toInt());
}

void MainWindow::on_pushButton_clicked()
{
    set_table();
    int num = ui->start->text().toInt();

    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(QString::number(num));
            num += ui->finish->text().toInt();
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QTableWidgetItem* tmp1 = ui->tableWidget->takeItem(ui->x1->text().toInt()-1, ui->y1->text().toInt()-1);
    QTableWidgetItem* tmp2 = ui->tableWidget->takeItem(ui->x2->text().toInt()-1, ui->y2->text().toInt()-1);
    ui->tableWidget->setItem(ui->x1->text().toInt()-1, ui->y1->text().toInt()-1, tmp2);
    ui->tableWidget->setItem(ui->x2->text().toInt()-1, ui->y2->text().toInt()-1, tmp1);
}
