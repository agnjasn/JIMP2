//
// Created by Kinga on 26.03.2017.
//
#include <string>
#include <vector>
#include <unordered_map>
#include "SimpleTemplateEngine.h"

namespace nets
{
    View::View(const std::string &pattern)
    {
        what_i_get=pattern;
    }

    std::string View::Render(const std::unordered_map <std::string, std::string> &model)const
    {
        std::string what_i_return=what_i_get;
        std::vector <std::string> word_matches;
        std::vector <std::string> word_matches_without_brackets;
        std::regex pattern("(\\{\\{\\w++\\}\\})");
        auto words_begin = std::sregex_iterator(what_i_get.begin(), what_i_get.end(), pattern);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) { //wyłapuje wszystkie pasujące napisy
            std::smatch matches = *i;
            word_matches.push_back(matches.str()); //wklada je do wektora
        }
        word_matches_without_brackets=word_matches; //dodatkowy wketor na zmienne bez {{ i }}
        for(int i=0; i<word_matches_without_brackets.size(); i++) //to usuwa {{ i }}
        {
            word_matches_without_brackets[i].erase(0,2);
            word_matches_without_brackets[i].erase(word_matches_without_brackets[i].length()-2,2);

        }


        std::string element_from_map;
        for(int i=0; i<word_matches.size(); i++)
        {
            std::unordered_map<std::string,std::string>::const_iterator got= model.find(word_matches_without_brackets[i]); //znajduje w mapie i zwraca wskaznik na odpowiednie elementy
            if ( got == model.end() ) //jesli nie znajdzie w mapie to ma wpisac nic
            {
                element_from_map="";
            }
            else
            {
                element_from_map = got->second; //a jak znajdzie to przypisac do zmiennej ten element
            }
            what_i_return.replace(what_i_return.find(word_matches[i]),word_matches[i].length(), element_from_map); //szukamy w zmiennej pasujacych słów z word_matches
                                    //potem zamieniamy je z elementem w element_from_map
        }
        return what_i_return;
    }

}
