//
// Created by Kinga on 07.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H


#include <iostream>
#include <list>
#include <set>
#include <initializer_list>
#include <iterator>
#include "Word.h"
#include "Counts.h"

namespace datastructures
{

    class WordCounter
    {
    public:
        WordCounter();
        Counts operator[](std::string s);
        friend class Counts;
        friend class Word;
        WordCounter (const std::initializer_list<Word> &m)
        {
            wc.resize(0);
            for (std::initializer_list<Word>::iterator it=m.begin(); it!=m.end(); it++)
            {
                Word tmp(*it);
                bool d= false;
                if(wc.size()!=0)
                {
                    for (std::list<std::pair<Word, Counts>>::iterator i=wc.begin(); i!=wc.end(); i++)
                    {
                        if (i->first==tmp)
                        {
                            i->second.Set(i->second.Get()+1);
                            d=true;
                            break;
                        }
                    }
                }

                if(d== false)
                {
                    wc.push_back(std::pair<Word, Counts>(tmp, 1));
                }


            }

        }
       int  DistinctWords();
        int TotalWords();
        std::set<Word> Words();

    private:
        std::list<std::pair<Word,Counts>> wc;

    };



}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
