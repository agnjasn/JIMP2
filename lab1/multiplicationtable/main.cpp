//
// Created by agnieszka on 04.03.17.
//

#include <MultiplicationTable.h>
#include <iostream>

using namespace std;
int main()
{
    int tab[10][10];
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            tab[i][j]=0;
        }
    }
    MultiplicationTable(tab);
    ViewTable(tab);
    return 0;
}