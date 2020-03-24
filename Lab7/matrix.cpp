#include "matrix.h"

Matrix::Matrix()
{
    matrix = nullptr;
}

Matrix::Matrix(int rows, int colons):
rows(rows), colons(colons)
{
    matrix = new double *[rows];
    for(int i = 0; i<rows; ++i)
        matrix[i] = new double [colons];
}

Matrix::Matrix(const Matrix &old)
{
    this->rows = old.get_rows();
    this->colons = old.get_colons();
    this->matrix = new double *[this->rows];
    for(int i = 0; i<this->rows; ++i)
        this->matrix[i] = new double [this->colons];
}

Matrix::~Matrix()
{
    for(int i = 0; i<rows; ++i)
        delete [] matrix[i];
    delete [] matrix;
}

void Matrix::set_size(int row, int colon)
{
    this->rows = row;
    this->colons = colon;
    if(!matrix)
    {
        matrix = new double *[row];
        for(int i = 0; i < row; ++i)
            matrix[i] = new double [colon];
    }
    else
    {
        auto **tmp = new double *[row];
        for(int i = 0; i < row; ++i)
            tmp[i] = new double [colon];
        for(int i = 0; i<rows; ++i)
            for(int j = 0; j<colons; ++j)
                tmp[i][j] = matrix[i][j];
        for(int i = 0; i<rows; ++i)
            delete [] matrix[i];
        delete [] matrix;
        matrix = tmp;
    }
}

int Matrix::get_rows() const
{
    return rows;
}

int Matrix::get_colons() const
{
    return colons;
}

double & Matrix::at(int row, int colon)
{
    return *(*(matrix + row)+colon);
}

double Matrix::max()
{
    double max = matrix[0][0];
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            if(matrix[i][j]>max)
                max = matrix[i][j];
    return max;
}

double Matrix::min()
{
    double min = matrix[0][0];
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            if(matrix[i][j]<min)
                min = matrix[i][j];
    return min;
}

double Matrix::max_in_row(int row)
{
    double max = matrix[row][0];
    for(int j = 0; j<colons; ++j)
            if(matrix[row][j]>max)
                max = matrix[row][j];
    return max;
}

double Matrix::min_in_colon(int colon)
{
    double min = matrix[0][colon];
    for(int i = 0; i<rows; ++i)
            if(matrix[i][colon]<min)
                min = matrix[i][colon];
    return min;
}

Matrix::R Matrix::operator[](int row)
{
    return R(*this,row);
}

Matrix& Matrix::operator=(Matrix m2)
{
    if(this == &m2)
        return *this;
    for(int i = 0; i<rows; ++i)
        delete [] matrix[i];
    delete [] matrix;
    this->rows = m2.get_rows();
    this->colons = m2.get_colons();
    this->matrix = new double *[rows];
    for(int i = 0; i<rows; ++i)
        this->matrix[i] = new double [colons];
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            this->matrix[i][j] = m2[i][j];
    return *this;
}

Matrix Matrix::operator+(Matrix &m2)
{
    if(this->get_rows()!=m2.get_rows() || this->get_colons()!=m2.get_colons())
        return *this;
    Matrix res(this->get_rows(), this->get_colons());
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            res[i][j] = (*this)[i][j] + m2[i][j];
    return res;
}


Matrix & Matrix::operator+=(double &num)
{
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            (*this)[i][j] +=num;
    return *this;
}

Matrix Matrix::operator-(Matrix &m2)
{
    if(this->get_rows()!=m2.get_rows() || this->get_colons()!=m2.get_colons())
        return *this;
    Matrix res(this->get_rows(), this->get_colons());
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            res[i][j] = (*this)[i][j] - m2[i][j];
    return res;
}

Matrix & Matrix::operator-=(double &num)
{
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            (*this)[i][j] -=num;
    return *this;
}

Matrix Matrix::operator*(Matrix &m2)
{
    if(this->get_colons()!=m2.get_rows())
        return *this;
    Matrix res(this->get_rows(), m2.get_colons());
    double tmp;
    for(int i = 0; i<res.get_rows(); ++i)
        for(int j = 0; j<res.get_colons(); ++j)
        {
            tmp = 0;
            for (int k = 0; k<this->get_colons();++k)
                tmp += (*this)[i][k]*m2[k][j];
            res[i][j] = tmp;
        }
    return res;
}

Matrix & Matrix::operator*=(double &num)
{
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            (*this)[i][j] *=num;
    return *this;
}
