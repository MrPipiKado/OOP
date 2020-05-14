#include "matrix.h"
#include <exception>
#include <ctime>
#include <fstream>
#include <string.h>

void loggingg(const char * info)
{
    std::ofstream LOG;
    LOG.open ("/tmp/OOPLab.log", std::ios_base::out | std::ios_base::app);
    if(!LOG.good())throw bad_logging();
    time_t now = time(0);
    char* dt = ctime(&now);
    int len = strlen(dt);
    dt[len-1] = '\0';
    LOG << "[" << dt << "] " << info << std::endl;
    LOG.close();

}

Matrix::Matrix()
{
    colons = 0;
    rows = 0;
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
    for(int i = 0; i<this->rows; ++i)
        for(int j = 0; j<this->colons; ++j)
            this->matrix[i][j] = old.at(i, j);
}

Matrix::~Matrix()
{
    for(int i = 0; i<rows; ++i)
        delete [] matrix[i];
    delete [] matrix;
}

void Matrix::set_size(int row, int colon)
{
    if(!matrix || this->rows>row || this->colons> colon)
    {
        for(int i = 0; i<rows; ++i)
            delete [] matrix[i];
        delete [] matrix;
        matrix = new double *[row];
        for(int i = 0; i < row; ++i)
            matrix[i] = new double [colon];
        this->rows = row;
        this->colons = colon;
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
        this->rows = row;
        this->colons = colon;
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

double & Matrix::at(int row, int colon) const
{
    if(row>this->rows-1||colon>this->colons-1)throw out_of_bounds();
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

Matrix& Matrix::operator=(const Matrix& m2)
{
    if(this == &m2)
        return *this;
    if(!matrix)
    {
        for (int i = 0; i < rows; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }
    this->rows = m2.get_rows();
    this->colons = m2.get_colons();
    this->matrix = new double *[rows];
    for(int i = 0; i<rows; ++i)
        this->matrix[i] = new double [colons];
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            this->matrix[i][j] = m2.at(i,j);
    return *this;
}

Matrix Matrix::operator+(Matrix &m2)
{
    if(this->get_rows()!=m2.get_rows() || this->get_colons()!=m2.get_colons())
        throw mismatch();
    Matrix res(this->get_rows(), this->get_colons());
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            res[i][j] = (*this)[i][j] + m2[i][j];
    return res;
}


Matrix & Matrix::operator+=(const double &num)
{
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            (*this)[i][j] +=num;
    return *this;
}

Matrix Matrix::operator-(Matrix &m2)
{
    if(this->get_rows()!=m2.get_rows() || this->get_colons()!=m2.get_colons())
        throw mismatch();
    Matrix res(this->get_rows(), this->get_colons());
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            res[i][j] = (*this)[i][j] - m2[i][j];
    return res;
}

Matrix & Matrix::operator-=(const double &num)
{
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            (*this)[i][j] -=num;
    return *this;
}

Matrix Matrix::operator*(Matrix &m2)
{
    if(this->get_colons()!=m2.get_rows())
        throw mismatch();
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

Matrix & Matrix::operator*=(const double &num)
{
    for(int i = 0; i<rows; ++i)
        for(int j = 0; j<colons; ++j)
            (*this)[i][j] *=num;
    return *this;
}

void operator>>(QTableWidget *table, Matrix& op)
{
    bool ok;
    for(int i = 0; i < table->rowCount(); i++)
        for(int j = 0; j < table->columnCount(); j++)
        {
            table->item(i,j)->text().toDouble(&ok);
            if(!ok)throw bad_convert();
            op[i][j] = table->item(i,j)->text().toDouble();
        }
}

void operator<<(QTextEdit *text, Matrix& op)
{
    QString tmp ="";
    for(int i = 0; i < op.get_rows(); i++)
    {
        for(int j = 0; j < op.get_colons(); j++)
        {
            tmp += QString::number(op[i][j], 'g', 2) + " ";
        }
        tmp += "\n";
    }
    text->setText(tmp);
}

void operator<<(QTableWidget *table, Matrix& op)
{
    for(int i = 0; i < table->rowCount(); i++)
        for(int j = 0; j < table->columnCount(); j++)
        {
            table->item(i, j)->setText(QString::number(op[i][j]));
        }
}
