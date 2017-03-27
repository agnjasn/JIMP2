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
//    vector <string> word_matches;
    string what_i_get="Hello {{name}}! How are you today? My name is {{program}}!";
//    std::regex pat("(\\{\\{\\w+\\}\\})");
//
//    auto words_begin = std::sregex_iterator(s.begin(), s.end(), pat);
//    auto words_end = std::sregex_iterator();
//    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
//        std::smatch matches = *i;
//        word_matches.push_back(matches.str());
//
//    }
//
//    for(int i=0; i<word_matches.size(); i++)
//    {
//        word_matches[i].erase(0,2);
//        word_matches[i].erase(word_matches[i].length()-2,2);
//        std::cout<<word_matches[i]<<std::endl;
//    }

    std::string what_i_return="";
    std::vector <std::string> word_matches;
    std::unordered_map <std::string, std::string> model={{"name", "Zbyszek"}, {"program", "Borg"}};
    std::regex pat("(\\{\\{\\w++\\}\\})");
    auto words_begin = std::sregex_iterator(what_i_get.begin(), what_i_get.end(), pat);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch matches = *i;
        word_matches.push_back(matches.str());
    }

    for(int i=0; i<word_matches.size(); i++)
    {
        word_matches[i].erase(0,2);
        word_matches[i].erase(word_matches[i].length()-2,2);
        std::cout<<model.at(word_matches[i])<<std::endl;
    }
    cout<<word_matches.size();


    for(int i=0; i<word_matches.size(); i++)
   {
        what_i_return=regex_replace(what_i_get, pat, model.at(word_matches[i]));
    }
    cout<<what_i_return<<std::endl;
    return 0;
}
