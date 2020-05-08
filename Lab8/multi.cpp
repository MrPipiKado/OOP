#include "multi.h"
#include "ui_multi.h"

multi::multi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multi)
{
    ui->setupUi(this);
}

multi::~multi()
{
    delete ui;
}
