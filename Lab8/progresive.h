#ifndef PROGRESIVE_H
#define PROGRESIVE_H

#include <QWidget>
#include "accounts.h"
namespace Ui {
class Progresive;
}

class Progresive : public QWidget
{
    Q_OBJECT

public:
    explicit Progresive(QWidget *parent = nullptr);
    ~Progresive();

private slots:
    void on_pushButton_clicked();

    void on_term_valueChanged(int arg1);

    void on_pushButton_2_clicked();

private:
    Ui::Progresive *ui;
    AccountProgressive acc;
};

#endif // PROGRESIVE_H
