//
// Created by agnieszka on 04.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <iostream>

namespace academia
{
    class TeacherId
    {
    public:
        TeacherId(){}
        TeacherId(int id_): id2(id_){}
        int Id(){return id2;}
        operator int() {return id2;}
        int id2;
    };

    class Teacher
    {
    public:
        Teacher(){}
        Teacher(TeacherId id_, std::string name_, std::string department_): id(id_), name(name_), department(department_){}
        std::string Name(){return name;}
        std::string Department(){ return department;}
        TeacherId Id(){ return id;}

        std::string name;
        std::string department;
        TeacherId id;
    };
    bool operator==(const TeacherId &t, const TeacherId &t2){return t2.id2==t.id2;}
    bool operator==(const Teacher &t, const Teacher &t2){return t.id==t2.id && t.name==t2.name && t.department==t2.department;}
    bool operator!=(const TeacherId &t, const TeacherId &t2){return t2.id2!=t.id2;}
    bool operator!=(const Teacher &t, const Teacher &t2){return t.id!=t2.id || t.name!=t2.name || t.department!=t2.department;}
    std::size_t operator*(TeacherId tea, size_t val){return tea.id2*val;}
    struct TeacherHash {
       std::size_t operator()(Teacher const &teacher1) const
       {
           std::size_t h1 = std::hash<std::string>{}(teacher1.name);
           std::size_t h2 = std::hash<std::string>{}(teacher1.department);
           return (teacher1.id*h1+h2);
       }
    };

}



#endif //JIMP_EXERCISES_TEACHERHASH_H
