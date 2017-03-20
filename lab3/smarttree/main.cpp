//
// Created by agnieszka on 18.03.17.
//
#include "SmartTree.h"
#include <iostream>
using namespace datastructures;
int main()
{
    std::string tree="[12 [3 [none] [none]] [56 [none] [none]]]";
    std::string tmp="";
    for(int i=0; i<tree.length(); i++)
    {

        if(tree[i]>='0' && tree[i]<='9')
        {
            tmp+=tree[i];
        }
        else if(tree[i]=='n')
        {
            tmp+="#";
            i+=4;
        }
        else if(tree[i]==' ') tmp+=" ";
    }
    std::cout<<tmp;
    return 0;
}
