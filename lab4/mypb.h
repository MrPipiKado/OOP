#ifndef MYPB_H
#define MYPB_H
#include <QPushButton>
#include <QWidget>

class MYPB : public QPushButton
{
public:
    MYPB(QWidget* parent = Q_NULLPTR);
    unsigned int number;
};

#endif // MYPB_H
