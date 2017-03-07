//
// Created by agnieszka on 06.03.17.
//

#include "DoubleBasePalindromes.h"
using namespace std;

uint64_t DoubleBasePalindromes(int max_vaule_exculsive) {
    uint64_t sum=0;
    for (int i = 0; i < max_vaule_exculsive; i++)
    {
        string max_ve, value_in_2, tmp;
        sprintf((char *) tmp.c_str(), "%d", i);
        max_ve=tmp.c_str();
        value_in_2=conversion_to_2(i);
        if(IsPalindrome(max_ve)==1 && IsPalindrome(value_in_2)==1) sum+=i;

    }
    return sum;
}

bool IsPalindrome(string str)
{
    unsigned long size=str.length();
    for (int i=0; i<(str.length()/2); i++)
    {
        if(str[i]!=str[size-1]) return 0;
        size --;
    }
    return 1;
}

string conversion_to_2(int value)
{
    string value_in_2;
    while(value) {
        value_in_2 =(value%2?"1":"0") +value_in_2;
        value/=2;
    }
    return value_in_2;
}