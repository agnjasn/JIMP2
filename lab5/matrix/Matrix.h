//
// Created by agnieszka on 02.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include <complex>
#include <string.h>
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

        std::complex<double> Get() const;
        void Set(std::complex<double> value);

        std::complex<double> **add(std::complex<double> **m2);
        std::complex<double> **sub(std::complex<double> **m2);
        std::complex<double> **mul(std::complex<double> **m2);
        std::complex<double> **div(std::complex<double> **m2);
        std::complex<double> **mul(std::complex<double> value);
        std::complex<double> **div(std::complex<double> value);
        std::complex<double> **pow(int pot);

        void print(std::complex<double> **m);


    private:
        int rows;
        int col;
        std::complex<double> **mat;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
