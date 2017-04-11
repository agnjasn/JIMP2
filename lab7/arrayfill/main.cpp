//
// Created by Kinga on 11.04.2017.
//

#include <iostream>
#include <ArrayFill.h>
#include <vector>
using namespace arrays;
int main()
{
    std::vector<int> vs;
    FillArray(1024, UniformFill {77}, &vs);
    return 0;
}