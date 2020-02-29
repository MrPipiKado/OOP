#include "mylabel.h"
MyLabel::MyLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    Piece = ' ';
}

MyLabel::~MyLabel() {}
