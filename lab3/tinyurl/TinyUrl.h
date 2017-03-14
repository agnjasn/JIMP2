//
// Created by Kinga on 14.03.2017.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <utility>
#include <string>
#include <array>
#include <memory>

using namespace std;

struct TinyUrlCodec
{};

std::unique_ptr<TinyUrlCodec> Init();
void NextHash(std::array<char, 6> *state);
std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);


#endif //JIMP_EXERCISES_TINYURL_H
