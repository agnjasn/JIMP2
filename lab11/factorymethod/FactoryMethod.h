//
// Created by Kinga on 23.05.2017.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <iostream>

namespace factoryMethod
{
    template <class T>
    T Create ()
    {
        return T();
    }

    class  MyType
    {
    public:
        std::string SayHello()
        {
            return "hello";
        }

    };

}



#endif //JIMP_EXERCISES_FACTORYMETHOD_H
