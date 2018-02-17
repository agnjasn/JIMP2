//
// Created by Kinga on 19.04.2017.
//

#include "Point3D.h"
#include "Point.h"
#include <iostream>

int main(void)
{

    geometry::Point3D A{}, B(3,4,5);
    std::cout<<A.Distance(B)<<std::endl;
    geometry::Point3D punkt3d(3,4,5);
    geometry::Point punkt2d(2,1);
    std::cout<<punkt2d.Distance(punkt3d)<<std::endl;
    geometry::Point3D p3d(1,2,3);
    std::cout << p3d << std::endl;

    return 0;
}
//zad 5
//Wywołują się w kolejności:
//Konstruktor bezparametryczny 2D
//Konstruktor bezparametryczny 3D
//Konstruktor parametryczny 2D
//Konstruktor parametryczny point 3D
//Destruktor 3D
//Destruktor 2D
//Destruktor 3D
//Destruktor 2D

//zad6
//została wywołana funkcja Distance dla Point, pominięto ostatnią wartość punkt3d

//zad7
//wywoła się operator dla Point i wypisze tylko dwie pierwsze wartości