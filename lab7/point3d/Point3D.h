//
// Created by Kinga on 19.04.2017.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H

#include "Point.h"

namespace geometry
{

    class Point3D : public Point
    {
    public:
        Point3D();
        Point3D(double a, double b, double c);
        double Distance(const Point3D &other);
        void Print()const ;


    private:
        double z_;

    };
}


#endif //JIMP_EXERCISES_POINT3D_H
