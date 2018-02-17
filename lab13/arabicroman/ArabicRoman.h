//
// Created by kb on 06.06.17.
//

#ifndef JIMP_EXERCISES_ARABICROMAN_H
#define JIMP_EXERCISES_ARABICROMAN_H

#include <iostream>
#include <string>

class Negative
{
public:
    Negative(){}
};
std::string f(int a, std::string* tab)
{
    if(a==0) return "";
    if(a==1) return tab[0];
    if(a==2) return tab[0]+tab[0];
    if(a==3) return tab[0]+tab[0]+tab[0];
    if(a==4) return tab[0]+tab[1];
    if(a==5) return tab[1];
    if(a==6) return tab[1]+tab[0];
    if(a==7) return tab[1]+tab[0]+tab[0];
    if(a==8) return tab[1]+tab[0]+tab[0]+tab[0];
    if(a==9) return tab[0]+tab[2];




}

std::string ArabicToRoman(int arab)
{
     std::string roman="";
    if(arab<0) throw Negative{};
     std::string t[3]={"M","M","M"}, h[3]={"C", "D", "M"}, d[3]={"X", "L", "C"}, o[3]={"I", "V", "X"};
    roman+=f((arab%10000)/1000,t)+f((arab%1000)/100,h)+f((arab%100)/10,d)+f(arab%10,o);
    return roman;
}

int foo(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int RomanToArabic(std::string str)
{

    int arab = 0;

    // Traverse given input
    for (int i=0; i<str.length(); i++)
    {
        // Getting value of symbol s[i]
        int s1 = foo(str[i]);

        if (i+1 < str.length())
        {
            // Getting value of symbol s[i+1]
            int s2 = foo(str[i+1]);

            // Comparing both values
            if (s1 >= s2)
            {
                // Value of current symbol is greater
                // or equal to the next symbol
                arab = arab + s1;
            }
            else
            {
                arab = arab + s2 - s1;
                i++; // Value of current symbol is
                // less than the next symbol
            }
        }
        else
        {
            arab = arab + s1;
            i++;
        }
    }
    return arab;
}

#endif //JIMP_EXERCISES_ARABICROMAN_H
