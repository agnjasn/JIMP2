//
// Created by Kinga on 19.04.2017.
//

#include "Point3D.h"
#include <iostream>
#include <cmath>

namespace geometry
{
    Point3D::Point3D() : Point(), z_(0){}

    Point3D::Point3D(double a, double b, double c) : Point(a, b)
    {
        z_=c;
    }
    void Point3D::Print()const
    {
        std::cout<<x_<<endl<<y_<<endl<<z_<<endl;
    }

    double Point3D::Distance(const Point3D &other) {
        return sqrt(((x_-other.x_)*(x_-other.x_))
                    + ((y_-other.y_)*(y_-other.y_))
                    + ((z_-other.z_)*(z_-other.z_)));
    }

}