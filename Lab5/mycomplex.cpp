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

Complex Complex::add(const Complex &a)
{
    Complex res;
    res.set_real(this->real + a.real);
    res.set_imagine(this->imagine + a.imagine);
    res.trigonometry();
    return res;
}

Complex Complex::sub(const Complex &a)
{
    Complex res;
    res.set_real(this->real - a.real);
    res.set_imagine(this->imagine - a.imagine);
    res.trigonometry();
    return res;
}

Complex Complex::mul(const Complex &a)
{
    Complex res;
    res.set_real(this->real * a.real - this->imagine * a.imagine);
    res.set_imagine(this->real * a.imagine + this->imagine*a.real);
    res.trigonometry();
    return res;
}
Complex Complex::div(const Complex &a)
{
    Complex res;
    res.set_real((this->real * a.real + this->imagine * a.imagine)/(a.real*a.real + a.imagine*a.imagine));
    res.set_imagine((this->imagine * a.real - this->real*a.imagine)/(a.real*a.real + a.imagine*a.imagine));
    res.trigonometry();
    return res;
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
    Complex res;
    res.set_real(pow((sqrt(real*real+imagine*imagine)), (1./n))*
                 cos((imagine/real)/n));
    double imaginaryRoot = pow((sqrt(real*real+imagine*imagine), 1./base)*sin((imagine/real)/n));
    Complex root(realRoot, imaginaryRoot);
    return root;
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
