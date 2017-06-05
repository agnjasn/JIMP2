//
// Created by agnieszka on 05.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

#include <iostream>

template<class Id, class Count>
class SequentialIdGenerator
{
public:
    SequentialIdGenerator(const Count &licz=Count()): count{licz}{}
    Id NextValue()
    {
        Id id2=Id(count);
        ++count;
        return id2;}
private:
    Count count;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
