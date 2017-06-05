//
// Created by agnieszka on 05.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

#include <iostream>

template<class T, class U>
class SequentialIdGenerator
{
public:
    SequentialIdGenerator() {id_=0;}
    SequentialIdGenerator(const U &licz): licznik{licz}  {}
    SequentialIdGenerator(const T &id): id_{id} {}
    operator int() {return licznik;}
    T NextValue(){ T a; return a;};
private:
    T id_;
    U licznik;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
