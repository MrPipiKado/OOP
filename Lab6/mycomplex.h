#ifndef CLASSSS_COMPLEX_H
#define CLASSSS_COMPLEX_H

#include <cmath>
#include <string>
#include <QString>
#include <QLabel>
#include <QMainWindow>
#include "mylineedit.h"
class Complex
{
public:
    Complex(){++count;};
    Complex(double a);
    Complex(double a, double b);
    ~Complex(){--count;};
    Complex operator+ (const Complex& op2);
    Complex operator- (const Complex& op2);
    Complex operator* (const Complex& op2);
    Complex operator/ (const Complex& op2);
    Complex operator^ (int n);
    Complex root (int n);
    bool eql (const Complex& op2);
    double get_real () const ;
    double get_imagine () const ;
    void set_real(double a);
    void set_imagine(double a);
    friend void operator<<(QLabel* label, Complex &op);
    friend void operator>>(MyLineEdit* edit, Complex &op);
    static int get_count();
    std::string get_algebra();
    std::string get_trigonometry();
private:
    double real;
    double imagine;
    double r;
    double fi;
    inline void trigonometry();
    inline void algebra();

    static int count;
};

#endif //CLASSSS_COMPLEX_H
