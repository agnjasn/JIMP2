//
// Created by Pomidor on 23.05.2017.
//

#ifndef JIMP_EXERCISES_SUMATOR_H
#define JIMP_EXERCISES_SUMATOR_H

#include <iostream>
#include <vector>
#include <algorithm>


class Room
{
public:
    enum class Type {
        COMPUTER_LAB,
        LECTURE_HALL,
        CLASSROOM
    };
    Room() {}
    Room(int id, std::string name, Type type): id_(id), name_(name), type_(type){}
    int Id() const { return id_;}

    int id_;
    std::string name_;
    Type type_;
};

template <class T>
T Sum(T a, T b)
{
    return a+b;
}

template <class T>
auto Value (T input)
{
    return *input;
}

template <class T>
class Repository
{
public:
    size_t Size() { return repository_.size();}
    std::string operator[](int id)
    {
        auto n= std::find_if(repository_.begin(), repository_.end(), [id](T arg){return arg.Id();});
        return (*n).name_;
    }
    int NextId(){return id_++;}

    std::vector<T> repository_;
    int id_=0;

};

template <class T>
auto Mean(std::vector<T> vec)
{
    T sum=0;
    for (auto v : vec)
    {
        sum+=v;
    }
    return sum/vec.size();
}

#endif //JIMP_EXERCISES_SUMATOR_H
