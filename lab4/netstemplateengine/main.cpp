//
// Created by Kinga on 26.03.2017.
//

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include "SimpleTemplateEngine.h"

using namespace std;

//void MakeTemplate (const std::string &pattern)
//{
//    vector <string> parts;
//    vector <string> blanks;
//
//    bool in=0;
//    for (int i=0; i <pattern.size(); i++)
//    {
//        if (in==0)
//        {
//            parts.push_back("");
//            while(pattern[i]!='{' && pattern[i+1]!='{')
//            {
//                parts.back()+=pattern[i];
//                i++;
//            }
//            parts.back()+=pattern[i];
//            in=1;
//            i+=2;
//
//        } else
//        {
//            blanks.push_back("");
//            while(pattern[i]!='}' && pattern[i+1]!='}')
//            {
//                blanks.back()+=pattern[i];
//                i++;
//            }
//            blanks.back()+=pattern[i];
//            in=0;
//            i+=2;
//
//        }
//
//    }
//
//}

int main(void)
{
    string s="jeden++++{{name}}--dwa--{{age}}!!trzy!!{{sth}}**cztery";
    std::regex p ("\\{\\{(\\w++)\\}\\}");
    smatch matches;
    regex_match(s,matches,p);

    cout<<matches[0]<<endl;
    cout<<matches[1]<<endl;
    cout<<matches[2]<<endl;
    cout<<matches[3]<<endl;
    cout<<matches[4]<<endl;

    return 0;
}
