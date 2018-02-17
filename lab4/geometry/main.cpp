//
// Created by agnieszka on 21.03.17.
//

#include "Square.h"
#include "Point.h"
#include <iostream>
#include <sstream>
using namespace geometry;
 int main()
 {
     Point punkt;
     std::cin >> punkt;
     std::cout << punkt;
     std:stringstream ss;
     ss << punkt;
     std::cout<<ss.str();
     return 0;
 }