#ifndef PERCENTAGE_H
#define PERCENTAGE_H

#include <QWidget>
#include "accounts.h"
namespace Ui {
class Percentage;
}

class Percentage : public QWidget
{
    Q_OBJECT

public:
    explicit Percentage(QWidget *parent = nullptr);
    ~Percentage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Percentage *ui;
    AccountPercent acc;
};

#endif // PERCENTAGE_H
