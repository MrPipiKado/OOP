#ifndef CLASSSET_COMPLEX_H
#define CLASSSET_COMPLEX_H
#include <string>
#include <iostream>
class Complex
{
private:
    int real;
    int imaginary;
public:
    explicit Complex(int _real = 0, int _imaginary = 0);
    Complex operator+(const Complex& _complex) const;
    Complex operator-(const Complex& _complex) const;
    bool operator==(const Complex& _complex) const;
    friend std::ostream& operator<<(std::ostream& os, Complex &_complex);
};

#endif //CLASSSET_COMPLEX_H
