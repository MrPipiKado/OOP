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
     Complex add (const Complex&);
     Complex sub (const Complex&);
     Complex mul (const Complex&);
     Complex div (const Complex&);
     Complex pow (int n);
     Complex root (int n);
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
