//
// Created by Kinga on 12.03.2017.
//

#include "XorCypherBreaker.h"
#include <fstream>
#include <vector>

int main (void)
{
    const vector<char> cryptogram;
    const vector<string> dictionary;
    int key_length=3;

    XorCypherBreaker(cryptogram, key_length, dictionary);
    return 0;
}