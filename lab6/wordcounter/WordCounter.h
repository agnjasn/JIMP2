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

namespace datastructures
{
    class Counts
    {
    public:
        Counts();
        Counts(int val);
        bool operator==(Counts other) const;
        Counts& operator++();
        //Counts(Counts &&m);
       // Counts& operator=(Counts &&other);
        Counts operator+(int a);
        int Get() const;
        void Set(int a);
        operator int() const;
        friend class Word;
        friend class WordCounts;
    private:
        int counts_;
    };

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
