#include "progresive.h"
#include "ui_progresive.h"

Progresive::Progresive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Progresive)
{
    ui->setupUi(this);
    ui->percentage->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->percentage->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->percentage->setColumnCount(1);
}

Progresive::~Progresive()
{
    delete ui;
}

void Progresive::on_pushButton_clicked()
{
    if(ui->name->isEnabled())
    {

        ui->name->setEnabled(false);
        ui->surname->setEnabled(false);
        ui->sum->setEnabled(false);
        ui->term->setEnabled(false);
        ui->percentage->setEnabled(false);
        acc.set_sum(ui->sum->text().toDouble());
        acc.set_name((ui->name->text().toStdString()));
        acc.set_surname((ui->surname->text().toStdString()));
        acc.set_term(ui->term->text().toInt());
        ui->pushButton->setText("Edit");
        double tmp[acc.get_term()];
        for(int i = 0; i<acc.get_term(); ++i)
            tmp[i] = ui->percentage->itemAt(i, 0)->text().toDouble();
        acc.set_percentage(tmp);

    }
    else
    {
        ui->name->setEnabled(true);
        ui->surname->setEnabled(true);
        ui->sum->setEnabled(true);
        ui->pushButton->setText("Save");
        ui->term->setEnabled(true);
        ui->percentage->setEnabled(true);
    }
}

void Progresive::on_term_valueChanged(int arg1)
{
    ui->percentage->setRowCount(arg1);
}

void Progresive::on_pushButton_2_clicked()
{
    ui->result->setText(QString::number(acc.get_result()));
}
