//
// Created by Kinga on 19.04.2017.
//

#include "Point3D.h"
#include <iostream>

int main(void)
{

    geometry::Point3D A{}, B(3,4,5);
    std::cout<<A.Distance(B);

    return 0;
}