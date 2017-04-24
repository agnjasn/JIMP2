//
// Created by Kinga on 24.04.2017.
//

#include "Shape.h"
#include <iostream>

void Kolo::Rysuj() const {

    std::cout<<" # "<<std::endl<<"###"<<std::endl<<" # "<<std::endl;


}

Kolo::~Kolo() {

}

void Trojkat::Rysuj() const {

    int r=3;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<=i; j++)
        {
            std::cout << "$";
        }
        std::cout<< std::endl;
    }

}

Trojkat::~Trojkat() {

}

void Kwadrat::Rysuj() const {
int r=2;
    for(int i=0; i<r; i++)
    {
        for(int j=r; j>0; j--)
        {
            std::cout << "*";
        }
        std::cout<< std::endl;
    }
}

Kwadrat::~Kwadrat() {

}

Ksztalt::~Ksztalt() {

}
