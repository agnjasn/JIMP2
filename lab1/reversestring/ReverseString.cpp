//
// Created by agnieszka on 04.03.17.

#include "ReverseString.h"
using namespace std;

string reverse(string str)
{
    string reversestr;
    reversestr="";
    for(unsigned long i=str.length()-1; i>=0; i--)
    {
        reversestr+=str[i];
    }
    return reversestr;
}