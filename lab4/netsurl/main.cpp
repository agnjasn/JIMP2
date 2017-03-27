//
// Created by agnieszka on 21.03.17.
//

#include "SimpleUrl.h"
#include <regex>
#include <iostream>
int main()
{
    std::regex pat("\\{\\{\\w+\\}\\}");
    std::string line {"hello {{it_s_me}}++{{aga}}"};
    std::smatch matches;

    std::cout << matches.size()<<std::endl;
    int i=0;
    while (regex_search(line, matches, pat)) {
        std::cout << "udało się dopasować do linii: " << matches[i] << std::endl;
        i++;
        log = line.suffix();
    }
    return 0;
}