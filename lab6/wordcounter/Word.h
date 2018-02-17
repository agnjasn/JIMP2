//
// Created by agnieszka on 18.04.17.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <iostream>
#include <string>
namespace datastructures
{

    class Word
    {
    public:
        bool operator<(Word w2) const;
        bool operator==(Word w2) const;
        Word(std::string s);
        Word();
        friend class WordCounts;
        friend class Counts;
    private:
        std::string word_;

    };


}

#endif //JIMP_EXERCISES_WORD_H
