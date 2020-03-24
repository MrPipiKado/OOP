#ifndef CLASSSS_COMPLEX_H
#define CLASSSS_COMPLEX_H

#include <cmath>
#include <string>
#include <QTableWidget>
#include <QTextEdit>
#include <QString>

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
    double& at(int row, int colon);
    double max();
    double min();
    double max_in_row(int row);
    double min_in_colon(int colon);

    R operator[](int row);
    Matrix& operator=(Matrix m2);
    Matrix operator+(Matrix& m2);
    Matrix&operator+=(double &num);
    Matrix operator-(Matrix& m2);
    Matrix&operator-=(double &num);
    Matrix operator*(Matrix& m2);
    Matrix&operator*=(double &num);
    friend void operator>>(QTableWidget *table, Matrix& op);
    friend void operator<<(QTableWidget *table, Matrix& op);
    friend void operator<<(QTextEdit *text, Matrix& op);
private:
    int rows;
    int colons;
    double **matrix;
};

#endif //CLASSSS_COMPLEX_H
