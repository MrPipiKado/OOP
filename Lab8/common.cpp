#include "common.h"
#include "ui_common.h"
#include <QString>
Common::Common(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Common)
{
    ui->setupUi(this);
}

Common::~Common()
{
    delete ui;
}

void Common::on_pushButton_clicked()
{
    if(ui->name->isEnabled())
    {
        ui->name->setEnabled(false);
        ui->surname->setEnabled(false);
        ui->sum->setEnabled(false);
        acc.set_sum(ui->sum->text().toDouble());
        acc.set_name((ui->name->text().toStdString()));
        acc.set_surname((ui->surname->text().toStdString()));
        ui->pushButton->setText("Edit");
    }
    else
    {
        ui->name->setEnabled(true);
        ui->surname->setEnabled(true);
        ui->sum->setEnabled(true);
        ui->pushButton->setText("Save");
    }
}
