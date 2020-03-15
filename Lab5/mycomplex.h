#ifndef CLASSSS_COMPLEX_H
#define CLASSSS_COMPLEX_H

#include <cmath>
#include <string>
class Complex
{
public:
    Complex()= default;
    Complex(double);
    Complex(double, double);
    ~Complex()= default;
     void add (const Complex&);
     void sub (const Complex&);
     void mul (const Complex&);
     void div (const Complex&);
     void pow (int n);
     void root (int n);
     bool eql (const Complex&);
     double get_real () const ;
     double get_imagine () const ;
     void set_real(double);
     void set_imagine(double);
     std::string get_algebra();
     std::string get_trigonometry();
private:
    double real;
    double imagine;
    double r;
    double fi;
    inline void trigonometry();
    inline void algebra();
};

#endif //CLASSSS_COMPLEX_H
