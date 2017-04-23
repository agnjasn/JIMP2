//
// Created by Kinga on 24.04.2017.
//

#include "Shape.h"
#include <random>
#include <list>


int main(void)
{
    srand(time(NULL));

    std::list<Ksztalt*> List;

    for (int i=0; i<10; i++)
    {
        long r = random()%3;
        if (r==0) List.push_back(new Kolo());
        else if (r==1) List.push_back(new Trojkat());
        else if (r==2) List.push_back(new Kwadrat());

        List.back()->Rysuj();
    }

    for (std::list<Ksztalt*>::iterator iter=List.begin(); iter!=List.end(); iter++)
    {
        delete(*iter);
    }
    return 0;
}