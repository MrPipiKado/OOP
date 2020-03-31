#ifndef COMMON_H
#define COMMON_H

#include <QWidget>
#include "accounts.h"
namespace Ui {
class Common;
}

class Common : public QWidget
{
    Q_OBJECT

public:
    explicit Common(QWidget *parent = nullptr);
    ~Common();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Common *ui;
    Account acc;
};

#endif // COMMON_H
