//
// Created by agnieszka on 04.03.17.
//

#include "Palindrome.h"
#include <iostream>
using namespace std;

bool is_palindrome(string str)
{
    int size=str.length();
    for (int i=0; i<(str.length()/2); i++)
    {
        if(str[i]!=str[size-1]) return 0;
        size --;
    }
    return 1;
}