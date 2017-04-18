//
// Created by Kinga on 07.04.2017.
//

#include "WordCounter.h"

namespace datastructures
{

//    Counts::Counts(Counts &&m) {
//        counts_=0;
//        std::swap(m.counts_, counts_);
//    }
//    Counts& Counts::operator=(Counts &&other)
//    {
//        this->counts_=other.counts_;
//

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

}