//
// Created by agnieszka on 02.04.17.
//

#include "Matrix.h"
#include <string>
#include <sstream>
namespace algebra
{
    std::string dtos(double x) { // funkcja przerabiająca double na stringa BEZ ZER NA KOŃCU
        std::stringstream s;
        s << x;
        return s.str();
    }

    Matrix::Matrix() { // konstruktor bezparametrowy robiący pustą macierz

        size.first=0;
        size.second=0;
        data.resize(0);
    }

    Matrix::Matrix(int rows, int col) { //konstruktor parametrowy (parametryczny?) robiący macierz z podanych wymiarów
        size.first=rows; //przypisanie rozmiaru
        size.second=col;

        // TA LINIJKA JEST SUPER WAŻNA
        data.resize(rows); //nadaje rozmiar wektorwoi w ktorym przechowuje liczby macierzy
        //JAK JEJ NIE MA TO WYSKAKUJE TEN BŁĄD Z STACKDUMP FILE

        for(int i=0; i<rows; i++)
        {
            data[i].resize(col);
        }


    }

    Matrix::Matrix(const Matrix &m) { //konstruktor kopiujący
        size=m.Size();
        data=m.data;

    }

    Matrix::Matrix(const char *ch) {

    }

    Matrix::Matrix(std::string str) {

    }

    std::complex<double> Matrix::Get(int row, int col) const { // zwraca wartość podaneo elementu macierzy
        return data[row][col];
    }

    void Matrix::Set(std::complex<double> value, int row, int col) { // ustawia daną wartośc na danym elemencie macierzy

        data[row][col]=value;
    }

    algebra::Matrix Matrix::Add(const algebra::Matrix &m2) const {

        if (size.second != m2.size.second || size.first != m2.size.first) { // sprawdzanie czy wymiary są zgodne
            return Matrix(); //jak nie to zwróc pustą macierz
        } else {
            algebra::Matrix m3(size.first, size.second); // nowa macierz o wymiarach takich samych jak tamte
            size_t r = size.first, c = size.second;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    m3.Set(this->data[i][j] + m2.data[i][j], i, j); // przypisanie nowej macierzy wartości
                }
            }


            return m3;
        }
    }

    algebra::Matrix Matrix::Sub(const algebra::Matrix &m2) const {

        if (size.second!=m2.size.second || size.first!=m2.size.first) // czy wymiary zgodne
        {
            return Matrix(0,0); // jak nie to zwróć pustą
        } else{
            algebra::Matrix m3(size.first, size.second); //nowa
            size_t r=size.first, c=size.second;
            for(int i=0; i<r; i++)
            {
                for (int j=0; j<c; j++)
                {
                    m3.Set(this->data[i][j]-m2.data[i][j], i, j);
                }
            }


            return m3;
        }

    }

    algebra::Matrix Matrix::Mul(const algebra::Matrix &m2) const {
        if (size.second!=m2.size.first) // sprawdzenie cwymiarów czy można mnożyć
        {
            return Matrix(); // jak nie to zwrócenie pustej
        } else{

            Matrix m3(size.first, m2.size.second); // nowa macierz
            std::complex<double> tmp=0.; // tymczasowy complex
            for(int i=0; i<size.first; i++)
            {
                for(int j=0; j<m2.size.second; j++)
                {
                    for(int h=0; h<m2.size.first; h++)
                    {
                        tmp+=(data[i][h]*m2.data[h][j]); //sumowanie do tego tymczasowego elementu
                        // na 100% jest ok
                    }
                    m3.Set(tmp,i,j); // wpisanie gotowej sumy na odpowiednie miejsce
                    tmp=0.;

                }
            }
            return m3;
        }

    }


    algebra::Matrix Matrix::Div(const algebra::Matrix &m2) const {
        return algebra::Matrix{};
    }

    algebra::Matrix Matrix::Pow(int power) {
        if (size.second!=size.first) // sprawdzenie czy macierz jest kwadratowa
        {
            return Matrix{}; // jak nie to zwróc pustą
        } else
        if (power==1) return *this; //jak podnosi do pierwszej potęgi to zwróc co masz
        else if (power==0) { // jeśli podnosi do 0 potęgi
                            // to zwróc macierz diagonalną
            Matrix m3(size.first, size.second); //nowa macierz o wymiarach takich jak pierwotna
            for (int j=0; j<size.first; j++)
            {
                m3.Set(1.0+0.i, j, j); // zwrobienie z niej macierzy diagonalnej
                // zera poza przekątną się robią same
            }
            return m3;
        } else { // jeśli jakaś inna potęga
            Matrix m3 = this->Mul(*this);  // zrob nowa macierz na podstawie wymnożonej tej samej ze sobą
            if (power==2) return m3; // jeśli potega 2 to ją zwroc
            else{ // a jeśli nie
                for (int i=1; i<=power-2; i++)
                {
                    m3 = m3.Mul(*this);  // to mnóż tę nową macierz przez this macierz odpowiednią ilość razy
                }
                return m3;
            }
        }
    }

    std::string Matrix::Print()const  {

        if (data.size()==0)
            return "[]"; // jak macierz jest pusta to zwraca same []
        std::string printed="["; //początek stringa
        for (int i=0; i<this->size.first; i++)
        {
            for (int j=0; j<this->size.second; j++)
            {

                printed+= dtos(data[i][j].real()); //dodanie czesci rzeczywistej liczby zespolonej
                printed+= "i";
                printed+= dtos(data[i][j].imag()); //dodanie czesci urojonej liczby zespolonej
                printed+= ", ";
            }
            printed.pop_back(); //usuwa niepotrzebne ostatnie ", "
            printed.pop_back();
            printed+="; ";
        }
        printed.pop_back(); //usuwa niepotrzebne ostatnie "; "
        printed.pop_back();
        printed+="]"; // dodaje koniec stringa
        return printed;
    }

    std::pair<size_t, size_t> Matrix::Size() const {
        return size; // zwraca rozmiar macierzy
    }

    Matrix::~Matrix() { //destruktor

    }
}