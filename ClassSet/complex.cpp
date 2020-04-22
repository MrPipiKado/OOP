#include "complex.h"

Complex::Complex(int _real, int _imaginary)
{
    real = _real;
    imaginary = _imaginary;
}

Complex Complex::operator+(const Complex &_complex) const
{
    return Complex(real+_complex.real, imaginary+_complex.imaginary);
}

Complex Complex::operator-(const Complex &_complex) const
{
    return Complex(real-_complex.real, imaginary-_complex.imaginary);
}

bool Complex::operator==(const Complex &_complex) const
{
    return real == _complex.real && imaginary == _complex.imaginary;
}
std::ostream&operator<<(std::ostream& os, Complex &_complex)
{
    return os<<_complex.real<<" + ("<<_complex.imaginary<<")i\n";
}
