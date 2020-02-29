#ifndef MYLABLE_H
#define MYLABLE_H
#include <QLabel>
#include <QWidget>
#include <Qt>
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~MyLabel();
    unsigned int number;

signals:
    void clicked();

protected:
    //void mousePressEvent(QMouseEvent* event);
    char Piece;
};

#endif // MYLABLE_H
