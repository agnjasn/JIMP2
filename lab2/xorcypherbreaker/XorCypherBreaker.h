//
// Created by Kinga on 12.03.2017.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;


std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary);
std::string nextkey(std::string key);

#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
