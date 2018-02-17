//
// Created by Pomidor on 21.03.2017.
//

#include "Point.h"
#include <math.h>
#include <iomanip>
#include <iostream>

using ::std::istream;
using ::std::ws;

namespace geometry {
    Point::Point() : x_(0), y_(0)
    {
        std::cout<<"Konstruktor bezparametryczny 2D"<<std::endl;
    }

    Point::Point(double x, double y) {
        x_ = x;
        y_ = y;
        std::cout<<"Konstruktor parametryczny 2D"<<std::endl;
    }

    Point::~Point() {
        std::cout<<"Destruktor 2D"<<std::endl;
    }

    double Point::GetX() const
    {
        return x_;
    }

    double Point::GetY() const
    {
        return y_;
    }
    void Point::SetX(double x)
    {
        x_=x;
    }

    void Point::SetY(double y)
    {
        y_=y;
    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    void Point::ToString(ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    void CheckNextChar(char c, istream* is) {
        int next_char = is->peek();
        if (next_char != c) {
            throw runtime_error("invalid character");
        }
        is->ignore();
    }

    void IgnoreWhitespace(istream* is) {
        (*is) >> ws;
    }

    double ReadNumber(istream* is) {
        double d;
        (*is) >> d;
        return d;
    }
// Właściwa definicja, obydwa argumenty funkcji nie
//są zadeklarowane jako const, bo obydwa są modyfikowane
//wewnątrz funkcji (STL nie używa naszej konwencji z przekazywaniem
//przez wskaźnik)
    istream& operator>>(istream & input, Point& p){
        CheckNextChar('(', &input);
        p.SetX(ReadNumber(&input));
        CheckNextChar(',', &input);
        IgnoreWhitespace(&input);
        p.SetY(ReadNumber(&input));
        CheckNextChar(')', &input);
        return input;      // Umożliwia cin >> a >> b >> c;
    }

    ostream& operator<<(ostream & output, Point& p){
        output<<p.GetX()<<" "<<p.GetY()<<std::endl;
        return output;      // Umożliwia cin >> a >> b >> c;
    }

    stringstream& operator<<(std::stringstream & output, Point& point){
        output<<point.GetX()<<" "<<point.GetY();
        return output;
    }
}
