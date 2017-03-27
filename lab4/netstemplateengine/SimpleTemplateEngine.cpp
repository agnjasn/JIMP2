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

//    void View::MakeTemplate (const std::string &pattern)
//    {
//
//    }
    std::string View::Render(const std::unordered_map <std::string, std::string> &model)const
    {

    }


}