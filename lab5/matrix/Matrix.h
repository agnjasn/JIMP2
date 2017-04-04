//
// Created by agnieszka on 02.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include <complex>
#include <string.h>
#include <vector>
namespace algebra
{

    class Matrix
    {
    public:
        Matrix();
        Matrix(int rows, int col);
        Matrix(const Matrix &m);
        Matrix(const char* ch);
        Matrix(std::string str);
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &m):data(m)
        {
            size.first=data.size();
            size.second=data[0].size();

        }
        ~Matrix();

        std::complex<double> Get(int row, int col) const;
        void Set(std::complex<double> value, int row, int col);

        Matrix Add(const algebra::Matrix &m2)const ;
        Matrix Sub(const algebra::Matrix &m2)const ;
        Matrix Mul(const algebra::Matrix &m2)const ;
        Matrix Div(const algebra::Matrix &m2)const ;
        Matrix Pow(int power);

        std::pair<size_t, size_t> Size() const;

        std::string Print()const;



    private:
                //rows, cols
        std::pair<size_t , size_t > size;
        std::vector<std::vector<std::complex<double>>> data;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
