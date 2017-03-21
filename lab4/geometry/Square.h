//
// Created by agnieszka on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"
#include <math.h>
namespace geometry
{

    class Square {

    public:
        Square(geometry::Point PUL, Point PUR, Point PDL, Point PDR );
        ~Square();

        bool Check();
        double Circumference();
        double Area();

    private:
        Point L_up, R_up, L_down, R_down;
    };

}
#endif //JIMP_EXERCISES_SQUARE_H
