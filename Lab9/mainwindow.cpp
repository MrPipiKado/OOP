#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->acc_1->addItem("AccountProgresive");
    ui->acc_1->addItem("AccountPercentage");
    ui->acc_1->addItem("AccountMulti");
    ui->acc_2->addItem("AccountProgresive");
    ui->acc_2->addItem("AccountPercentage");
    ui->acc_2->addItem("AccountMulti");
    ui->acc_3->addItem("AccountProgresive");
    ui->acc_3->addItem("AccountPercentage");
    ui->acc_3->addItem("AccountMulti");
    for(int i = 0; i<3; ++i)
        buffer[i] = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_set_clicked()
{
    for(int i = 0; i<3; ++i)
        delete buffer[i];
    if(ui->acc_1->currentIndex()==0)
        buffer[0] = new AccountPercent();
    else if(ui->acc_1->currentIndex()==1)
        buffer[0] = new AccountProgressive();
    else if(ui->acc_1->currentIndex()==2)
        buffer[0] = new AccountMulti();

    if(ui->acc_2->currentIndex()==0)
        buffer[1] = new AccountPercent();
    else if(ui->acc_2->currentIndex()==1)
        buffer[1] = new AccountProgressive();
    else if(ui->acc_2->currentIndex()==2)
        buffer[1] = new AccountMulti();

    if(ui->acc_3->currentIndex()==0)
        buffer[2] = new AccountPercent();
    else if(ui->acc_3->currentIndex()==1)
        buffer[2] = new AccountProgressive();
    else if(ui->acc_3->currentIndex()==2)
        buffer[2] = new AccountMulti();

    ui->I_1->setText(QString::fromStdString(buffer[0]->print()));
    ui->I_2->setText(QString::fromStdString(buffer[1]->print()));
    ui->I_3->setText(QString::fromStdString(buffer[2]->print()));

    Account *account;
    AccountPercent *percent;
    AccountProgressive *progresive;
    AccountMulti *multi;

    QString tmp1 = "", tmp2 = "", tmp3 = "";

    if(account = dynamic_cast<Account*>(buffer[0]))
    {
        tmp1 = tmp1 + "Can be casted to Account\n";
    }
    if(percent = dynamic_cast<AccountPercent*>(buffer[0]))
    {
        tmp1 = tmp1 + "Can be casted to AccountPercent\n";
    }
    if(progresive = dynamic_cast<AccountProgressive*>(buffer[0]))
    {
        tmp1 = tmp1 + "Can be casted to AccountProgresive\n";
    }
    if(multi = dynamic_cast<AccountMulti*>(buffer[0]))
    {
        tmp1 = tmp1 + "Can be casted to AccountMulti\n";
    }
    ui->show_1->setText(tmp1);

    if(account = dynamic_cast<Account*>(buffer[1]))
    {
        tmp2 = tmp2 + "Can be casted to Account\n";
    }
    if(percent = dynamic_cast<AccountPercent*>(buffer[1]))
    {
        tmp2 = tmp2 + "Can be casted to AccountPercent\n";
    }
    if(progresive = dynamic_cast<AccountProgressive*>(buffer[1]))
    {
        tmp2 = tmp2 + "Can be casted to AccountProgresive\n";
    }
    if(multi = dynamic_cast<AccountMulti*>(buffer[1]))
    {
        tmp2 = tmp2 + "Can be casted to AccountMulti\n";
    }
    ui->show_2->setText(tmp2);

    if(account = dynamic_cast<Account*>(buffer[2]))
    {
        tmp3 = tmp3 + "Can be casted to Account\n";
    }
    if(percent = dynamic_cast<AccountPercent*>(buffer[2]))
    {
        tmp3 = tmp3 + "Can be casted to AccountPercent\n";
    }
    if(progresive = dynamic_cast<AccountProgressive*>(buffer[2]))
    {
        tmp3 = tmp3 + "Can be casted to AccountProgresive\n";
    }
    if(multi = dynamic_cast<AccountMulti*>(buffer[2]))
    {
        tmp3 = tmp3 + "Can be casted to AccountMulti\n";
    }
    ui->show_3->setText(tmp3);
}
