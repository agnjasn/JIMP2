//
// Created by agnieszka on 21.03.17.
//

#include "Square.h"
#include <iostream>
#include <math.h>




namespace geometry
{
    using namespace std;
    using ::std::ostream;
    using ::std::endl;


    Point::Point():x_(0),y_(0){
    }

    Point::Point(double x, double y){
        x_ = x;
        y_ = y;
    }

    Point::~Point(){
    }

    double Point::Distance(const Point &other) const{
        return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
    }

    void Point::ToString(ostream *out) const{
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }
}