//
// Created by agnieszka on 04.03.17.
//

#include "MultiplicationTable.h"
#include<iostream>
void MultiplicationTable(int tab[][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            tab[i][j]=(i+1)*(j+1);
        }
    }

}

void ViewTable(int tab[][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            std::cout<<tab[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}