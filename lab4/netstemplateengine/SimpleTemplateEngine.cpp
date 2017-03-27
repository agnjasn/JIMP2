//
// Created by Kinga on 26.03.2017.
//

#include <string>
#include <vector>
#include <unordered_map>
#include "SimpleTemplateEngine.h"
#include <iterator>
namespace nets
{

    View::View(const std::string &pattern)
    {
        what_i_get=pattern;
    }

//    void View::MakeTemplate (const std::string &pattern)
//    {
//
//    }
    std::string View::Render(const std::unordered_map <std::string, std::string> &model)const
    {
        std::string what_i_return="";
        std::vector <std::string> word_matches;
        std::regex pat("(\\{\\{\\w++\\}\\})");
        auto words_begin = std::sregex_iterator(what_i_get.begin(), what_i_get.end(), pat);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) { //wyłapuje wszystkie pasujące napisy
            std::smatch matches = *i;
            word_matches.push_back(matches.str()); //wklada je do wektora
        }

        for(int i=0; i<word_matches.size(); i++) //to usuwa {{ i }}
        {
            word_matches[i].erase(0,2);
            word_matches[i].erase(word_matches[i].length()-2,2);
            //std::cout<<word_matches[i]<<std::endl;
        }

        for(int i=0; i<word_matches.size(); i++) //tutaj idzie po regexie i zamienia to na to co jest w mapie, ale działa źle
        {                                       //bo zamienia wszystko z word_matches[0], nie widząc kolejnych, choć idzie po tablicy
            what_i_return=regex_replace(what_i_get, pat, model.at(word_matches[i]));
        }
        return what_i_return;
    }


}