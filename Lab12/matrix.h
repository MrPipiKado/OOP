#ifndef CLASSSS_COMPLEX_H
#define CLASSSS_COMPLEX_H

#include <cmath>
#include <string>
#include <QTableWidget>
#include <QTextEdit>
#include <QString>

#include <exception>
#include <ctime>
#include <fstream>

class bad_logging: public std::exception
{
public:
    bad_logging(){};
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
    { return "Logging can not be done!"; }
};

void loggingg(const char * info);

class out_of_bounds: public std::exception
{
public:
    out_of_bounds(){};
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
    { return "out of bounds"; }
};

class mismatch: public std::exception
{
public:
    mismatch(){};
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
    { return "mismatch of dimensions of matrices"; }
};

class bad_convert: public std::exception
{
public:
    bad_convert(){};
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
    { return "Can not convert to double"; }
};

class Matrix
{
public:
    class R
    {
    private:
        friend class Matrix;
        R(Matrix& parent,int row): m_parent(parent),m_row(row) {}
    public:
        double & operator[](int col) {return m_parent.at(m_row,col);}
    private:
        Matrix&  m_parent;
        int m_row;
    };

    Matrix();
    Matrix(int rows, int colons);
    Matrix(const Matrix& old);
    ~Matrix();
    void set_size(int row, int colon);
    int get_rows() const ;
    int get_colons() const ;
    double& at(int row, int colon) const;
    double max();
    double min();
    double max_in_row(int row);
    double min_in_colon(int colon);
         R operator[](int row);
    Matrix& operator=(const Matrix& m2);
    Matrix operator+(Matrix& m2);
    Matrix&operator+=(const double &num);
    Matrix operator-(Matrix& m2);
    Matrix&operator-=(const double &num);
    Matrix operator*(Matrix& m2);
    Matrix&operator*=(const double &num);
    friend void operator>>(QTableWidget *table, Matrix& op);
    friend void operator<<(QTableWidget *table, Matrix& op);
    friend void operator<<(QTextEdit *text, Matrix& op);
private:
    int rows;
    int colons;
    double **matrix;
};

#endif //CLASSSS_COMPLEX_H
