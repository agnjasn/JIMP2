//
// Created by agnieszka on 21.03.17.
//

#include "Square.h"
#include "Point.h"
#include <iostream>
#include <array>
#include <math.h>




namespace geometry
{
    using namespace std;
    using ::std::ostream;
    using ::std::endl;


    Square::Square(geometry::Point PUL, Point PUR, Point PDL, Point PDR )
    {

        if (PUL.Distance(PUR)==PUR.Distance(PDR)&&PUL.Distance(PUR)==PDR.Distance(PDL))
        {
            this->L_up=PUL;
            this->R_up=PUR;
            this->L_down=PDL;
            this->R_down=PDR;

        } else
        {
            this->L_up.SetX(0);
            this->L_up.SetY(0);
            this->R_up.SetX(0);
            this->L_down.SetX(0);
            this->R_down.SetX(0);
            this->R_up.SetY(0);
            this->L_down.SetY(0);
            this->R_down.SetY(0);
        }

    }
    Square::~Square()
    {}

    double Square::Circumference()
    {
        return 4*(this->L_up.Distance(L_down));
    }
    double Square::Area()
    {
        return this->L_up.Distance(L_down)*this->L_up.Distance(L_down);
    }

}