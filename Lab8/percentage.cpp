#include "percentage.h"
#include "ui_percentage.h"

Percentage::Percentage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Percentage)
{
    ui->setupUi(this);
}

Percentage::~Percentage()
{
    delete ui;
}

void Percentage::on_pushButton_clicked()
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
        acc.set_term(ui->term->text().toDouble());
        acc.set_percentage(ui->percentage->text().toDouble());
        ui->pushButton->setText("Edit");
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

void Percentage::on_pushButton_2_clicked()
{
    ui->result->setText(QString::number(acc.get_result()));
}
