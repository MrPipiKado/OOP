#ifndef MULTI_H
#define MULTI_H

#include <QWidget>

namespace Ui {
class multi;
}

class multi : public QWidget
{
    Q_OBJECT

public:
    explicit multi(QWidget *parent = nullptr);
    ~multi();

private:
    Ui::multi *ui;
};

#endif // MULTI_H
