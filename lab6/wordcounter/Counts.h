//
// Created by agnieszka on 18.04.17.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

#include <iostream>
#include <string>

namespace datastructures
{
    class Counts
    {
    public:
        Counts();
        Counts(int val);
        bool operator==(Counts other) const;
        Counts& operator++();
        bool operator<(Counts other) const;
        bool operator>(Counts other) const;
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
}


#endif //JIMP_EXERCISES_COUNTS_H
