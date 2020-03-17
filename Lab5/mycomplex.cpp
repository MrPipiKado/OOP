#include "mycomplex.h"

Complex::Complex(double a):
real(a),
imagine(0.)
{
    this->trigonometry();
}

Complex::Complex(double a, double b):
real(a),
imagine(b)
{
    this->trigonometry();
}

void Complex::trigonometry()
{
    this->r = sqrt(this->real*this->real+this->imagine*this->imagine);
    this->fi = asin(this->real/this->r);
}

void Complex::algebra()
{
    this->real = this->r * cos(this->fi);
    this->imagine = this->r * sin(this->fi);
}

void Complex::add(const Complex &a)
{
    this->real += a.real;
    this->imagine += a.imagine;
    this->trigonometry();
}

void Complex::sub(const Complex &a)
{
    this->real -= a.real;
    this->imagine -= a.imagine;
    this->trigonometry();
}

void Complex::mul(const Complex &a)
{
    this->real =this->real * a.real - this->imagine * a.imagine;
    this->imagine = this->real * a.imagine + this->imagine*a.real;
    this->trigonometry();
}
void Complex::div(const Complex &a)
{
    this->real =(this->real * a.real + this->imagine * a.imagine)/(a.real*a.real + a.imagine*a.imagine);
    this->imagine = (this->imagine * a.real - this->real*a.imagine)/(a.real*a.real + a.imagine*a.imagine);
    this->trigonometry();
}

Complex Complex::pow(int n)
{
    for(int i = 0; i<n; ++i)
        this->r *= this->r;
    this->fi *= n;
    this->algebra();
}

Complex Complex::root(int n)
{
    this->r = std::pow(this->r, 1./n);
    this->fi /= n;
    this->algebra();
}

bool Complex::eql(const Complex &a)
{
    return this->real==a.real&&this->imagine==a.imagine;
}

double Complex::get_real() const
{
    return this->real;
}

double Complex::get_imagine() const
{
    return this->imagine;
}

void Complex::set_real(double a)
{
    this->real = a;
    this->trigonometry();
}

void Complex::set_imagine(double a)
{
    this->imagine = a;
    this->trigonometry();
}

std::string Complex::get_algebra()
{
    return std::to_string(this->real) + " + (" + std::to_string(this->imagine) + ")i";
}

std::string Complex::get_trigonometry()
{
    return std::to_string(this->r) + "(cos(" + std::to_string(this->fi) +
            ") + i sin(" + std::to_string(this->fi) + "))";
}
