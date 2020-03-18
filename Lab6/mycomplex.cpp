#include "mycomplex.h"
#include <cmath>

int Complex::count = 0;

Complex::Complex(double a):
real(a),
imagine(0.)
{
    ++count;
    this->trigonometry();
}

Complex::Complex(double a, double b):
real(a),
imagine(b)
{
    ++count;
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

Complex Complex::operator+ (const Complex &op2)
{
    return Complex(this->real+op2.real,
                   this->imagine+op2.imagine);
}

Complex Complex::operator- (const Complex &op2)
{
    return Complex(this->real - op2.real,
                   this->imagine - op2.imagine);
}

Complex Complex::operator* (const Complex &op2)
{
    return Complex(this->real * op2.real - this->imagine * op2.imagine,
                   this->real * op2.imagine + this->imagine * op2.real);
}
Complex Complex::operator/ (const Complex &op2)
{
    return Complex((this->real * op2.real + this->imagine * op2.imagine)/
                   (op2.real*op2.real + op2.imagine * op2.imagine),
                   (this->imagine * op2.real - this->real * op2.imagine)/
                   (op2.real * op2.real + op2.imagine * op2.imagine));
}

Complex Complex::operator^ (int n)
{
    return Complex(std::pow(r, n) * cos(this->imagine / this->real * n),
                   std::pow(r, n) * sin(this->imagine / this->real * n));
}

Complex Complex::root(int n)
{
    double param = imagine/real;
    double realRoot = std::pow(r, 1./n)*cos(param/n);
    double imaginaryRoot = std::pow(r, 1./n)*sin(param/n);
    Complex root(realRoot, imaginaryRoot);
    return root;
}

bool Complex::operator== (const Complex& op2)
{
    return this->r==op2.r;
}

bool Complex::operator> (const Complex& op2)
{
    return this->r>op2.r;
}

bool Complex::operator< (const Complex& op2)
{
    return this->r<op2.r;
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

void operator<<(QLabel*label, Complex &op)
{
    label->setText(QString::number(op.real)+"+("+ QString::number(op.imagine) + ")i");
}

void operator>>(MyLineEdit * edit, Complex &op)
{
    if(edit->ID)
    {
        op.set_imagine(edit->text().toDouble());
    }
    else
    {
        op.set_real(edit->text().toDouble());
    }
}

int Complex::get_count()
{
    return count;
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
