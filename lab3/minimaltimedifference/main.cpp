//
// Created by Kinga on 14.03.2017.
//

#include "MinimalTimeDifference.h"
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace minimaltimedifference;

int main (void)
{
    string s1="", s2="", s3="";
    cin>>s1>>s2>>s3;
    vector <string> v={s1, s2, s3};

    cout<<MinimalTimeDifference(v);
    return 0;
}