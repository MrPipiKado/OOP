#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H
#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit(QWidget *parent = nullptr);
    //void contextMenuEvent(QContextMenuEvent *event);
};

#endif // MYLINEEDIT_H
