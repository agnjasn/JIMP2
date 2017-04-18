//
// Created by agnieszka on 18.04.17.
//

#include "Word.h"
namespace datastructures
{

    bool Word::operator<(Word w2) const {
        if(this->word_<w2.word_) return true;
        else return false;
    }

    bool Word::operator==(Word w2) const {
        if(this->word_==w2.word_)
            return true;
        else return false;
    }

    Word::Word()
    {

    }

    Word::Word(std::string s) {

        word_=s;
    }
}