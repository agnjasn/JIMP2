//
// Created by Kinga on 26.03.2017.
//
#include <unordered_map>
#include <iostream>
#include <vector>
#include <regex>

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H




namespace nets
{


    class View
    {
    public:
        View(const std::string &pattern);
        std::string Render(const std::unordered_map <std::string, std::string> &model)const;


    private:
        std::string what_i_get;

    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
