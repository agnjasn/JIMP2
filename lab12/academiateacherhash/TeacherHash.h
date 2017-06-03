//
// Created by agnieszka on 04.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <iostream>
using ::std::literals::string_literals::operator""s;
namespace academia
{
    class TeacherId
    {
    public:
        TeacherId(){}
        TeacherId(int id_): id(id_){}
        operator int() {return id;}
        size_t operator()()
        {

        }
    private:
        int id;
    };

    class Teacher
    {
    public:
        Teacher(){}
        Teacher(TeacherId id_, std::string name_, std::string department_): id(id_), name(name_), department(department_){}
        std::string Name(){return name;}
        std::string Department(){ return department;}
        TeacherId Id(){ return id;}
    private:
        std::string name;
        std::string department;
        TeacherId id;
    };



    class TeacherHash
    { public:
        TeacherHash(){}
        std::size_t hash(){ return 0;}
    };


}



#endif //JIMP_EXERCISES_TEACHERHASH_H
