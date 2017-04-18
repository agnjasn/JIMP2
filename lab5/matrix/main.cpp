//
// Created by agnieszka on 02.04.17.
//

#include <iostream>
#include "Matrix.h"
using std::cout;
using std::endl;
using namespace algebra;

int main(int argc, char* argv[]){
    Matrix m1{{1, 2, 3}, {2, 3, 4}};

    std::string a=m1.Print();
    //cout<<a;
    Matrix m2{{1, 0, 3, 6}, {1, 5, 3, 4}};
    Matrix m3=m1.Mul(m2);
    cout<<m3.Print();


//    Matrix m1(argv[1]);
//    Matrix m2(argv[2]);
//
//    cout << "Macierz pierwsza: " << m1.Print() << endl;
//    cout << "Macierz druga: " << m2.Print() << endl;
//
//    cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
//    cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;
//    cout << "Mnożenie" << (m1.Mul(m2)).Print() << endl;
//    cout << "Dzielenie" << (m1.Div(m2)).Print() << endl;
//    cout << "Potęgowanie" << (m1.Pow(2)).Print() << endl;
//    cout << "Potęgowanie" << (m2.Pow(2)).Print() << endl;

    return 0;
}
