//
// Created by agnieszka on 02.04.17.
//

#include "Matrix.h"
#include <string>
#include <sstream>
namespace algebra
{
    std::string dtos(double x) {
        std::stringstream s;  // Allocates memory on stack
        s << x;
        return s.str();       // returns a s.str() as a string by value
        // Frees allocated memory of s
    }

    Matrix::Matrix() {

    }

    Matrix::Matrix(int rows, int col) {
        size.first=rows;
        size.second=col;
        mat.resize(rows);

        for(int i=0; i<rows; i++)
        {
            mat[i].resize(col);
        }


    }

    Matrix::Matrix(const Matrix &m) {
        size=m.Size();
        mat=m.mat;

    }

    Matrix::Matrix(const char *ch) {

    }

    Matrix::Matrix(std::string str) {

    }

    std::complex<double> Matrix::Get(int row, int col) const {
        return mat[row][col];
    }

    void Matrix::Set(std::complex<double> value, int row, int col) {

        mat[row][col]=value;
    }

    algebra::Matrix Matrix::Add(const algebra::Matrix &m2) const {

        algebra::Matrix m3(size.first, size.second);
        size_t r=size.first, c=size.second;
        for(int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                m3.Set(this->mat[i][j]+m2.mat[i][j], i, j);
            }
        }


        return m3;
    }

    algebra::Matrix Matrix::Sub(const algebra::Matrix &m2) const {

        algebra::Matrix m3(size.first, size.second);
        size_t r=size.first, c=size.second;
        for(int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                m3.Set(this->mat[i][j]-m2.mat[i][j], i, j);
            }
        }


        return m3;
    }

    algebra::Matrix Matrix::Mul(const algebra::Matrix &m2) const {
        Matrix m3(size.first, m2.size.second);
        std::complex<double> tmp=0.;
        for(int i=0; i<size.first; i++)
        {
            for(int j=0; j<m2.size.second; j++)
            {
                for(int h=0; h<m2.size.first; h++)
                {
                    tmp+=(mat[i][h]*m2.mat[h][j]);
                }
                m3.Set(tmp,i,j);
                tmp=0.;

            }
        }
        return m3;
    }


    algebra::Matrix Matrix::Div(const algebra::Matrix &m2) const {
        return algebra::Matrix{};
    }

    algebra::Matrix Matrix::Pow(int pot) {
        return algebra::Matrix{};
    }

    std::string Matrix::Print()const  {

        std::string printed="[";
        for (int i=0; i<this->size.first; i++)
        {
            for (int j=0; j<this->size.second; j++)
            {

                printed+= dtos(mat[i][j].real());
                printed+= "i";
                printed+= dtos(mat[i][j].imag());
                printed+= ", ";
            }
            printed.pop_back();
            printed.pop_back();
            printed+="; ";
        }
        printed.pop_back();
        printed.pop_back();
        printed+="]";
        return printed;
    }

    std::pair<size_t, size_t> Matrix::Size() const {
        return size;
    }

    Matrix::~Matrix() {

    }
}