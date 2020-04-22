#include "complex.h"

Complex::Complex(int _real, int _imaginary)
{
    real = _real;
    imaginary = _imaginary;
}

Complex Complex::operator+(Complex &_complex)
{
    return Complex(real+_complex.real, imaginary+_complex.imaginary);
}

Complex Complex::operator-(Complex &_complex)
{
    return Complex(real-_complex.real, imaginary-_complex.imaginary);
}

bool Complex::operator==(const Complex &_complex)
{
    if(real == _complex.real && imaginary == _complex.imaginary)
        return true;
    return false;
}

QLabel * operator<<(QLabel *lable, Complex &_complex)
{
    lable->setText(QString::number(_complex.real) + " + (" +
                   QString::number(_complex.imaginary) + ")i\n");
    return lable;
}

QString Complex::print()
{
    return QString::number(real) + " + (" +
            QString::number(imaginary) + ")i\n";
}

QString Complex::get_real()
{
    return QString::number(real);
}

QString Complex::get_imag()
{
    return QString::number(imaginary);
}
