#ifndef COMPLEX_H
#define COMPLEX_H

#include <QString>
#include <QLabel>

class Complex
{
private:
    int real;
    int imaginary;
public:
    explicit Complex(int _real = 0, int _imaginary = 0);
    Complex operator+(Complex& _complex);
    Complex operator-(Complex& _complex);
    bool operator==(const Complex& _complex);
    QString print();
    QString get_real();
    QString get_imag();
    friend QLabel * operator<<(QLabel* lable, Complex &_complex);
};

#endif // COMPLEX_H
