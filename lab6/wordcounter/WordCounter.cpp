//
// Created by Kinga on 07.04.2017.
//

#include "WordCounter.h"

namespace datastructures
{

    Counts::Counts() {
        counts_=0;
    }

    int Counts::Get() const
    {
        return counts_;
    }

    void Counts::Set(int a)
    {
        counts_=a;
    }

    Counts::Counts(int val) {

        counts_=val;
    }

    bool Counts::operator==(Counts other) const {
        if(this->counts_==other.counts_)
            return true;
        else return false;
    }
//    Counts::Counts(Counts &&m) {
//        counts_=0;
//        std::swap(m.counts_, counts_);
//    }
//    Counts& Counts::operator=(Counts &&other)
//    {
//        this->counts_=other.counts_;
//    }

    Counts& Counts::operator++() {

        counts_=counts_+1;
        return *this;
    }

    Counts Counts::operator+(int a)
    {
        return Counts(counts_+a);
    }

    Counts::operator int() const
    {
        return counts_;
    }

    Word::Word()
    {

    }

    Word::Word(std::string s) {

        word_=s;
    }

    int WordCounter::DistinctWords() {
        return wc.size();
    }

    int WordCounter::TotalWords() {
        int tmp=0;
        for (auto i: wc) {
            tmp+=i.second.Get();
        }
        return tmp;
    }

    WordCounter::WordCounter() {

        wc.resize(0);
    }

    Counts WordCounter::operator[](std::string s){

        for (auto i : wc)
        {
            if(i.first==s)
            {
                return i.second;
            }
        }
        return Counts(0);
    }


    std::set<Word> WordCounter::Words() {
        std::set<Word> ws;
        for(auto i: wc)
        {
            ws.emplace(i.first);
        }
        return ws;
    }

    bool Word::operator<(Word w2) const {
        if(this->word_<w2.word_) return true;
        else return false;
    }

    bool Word::operator==(Word w2) const {
        if(this->word_==w2.word_)
            return true;
        else return false;
    }
}