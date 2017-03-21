//
// Created by Pomidor on 21.03.2017.
//

#include "Point.h"
#include <math.h>

namespace geometry {
    Point::Point() : x_(0), y_(0) {
    }

    Point::Point(double x, double y) {
        x_ = x;
        y_ = y;
    }

    Point::~Point() {
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
}