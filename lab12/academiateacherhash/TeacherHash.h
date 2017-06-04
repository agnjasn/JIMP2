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
        int Id() const {return id2;}
        operator int() {return id2;}
    private:
        int id2;
    };

    class Teacher
    {
    public:
        Teacher(){}
        Teacher(TeacherId id_, std::string name_, std::string department_): id(id_), name(name_), department(department_){}
        std::string Name() const {return name;}
        std::string Department() const { return department;}
        TeacherId Id() const { return id;}
    private:
        std::string name;
        std::string department;
        TeacherId id;
    };
    bool operator==(const TeacherId &t, const TeacherId &t2){return t2.Id()==t.Id();}
    bool operator==(const Teacher &t, const Teacher &t2){return t.Id()==t2.Id() && t.Name()==t2.Name() && t.Department()==t2.Department();}
    bool operator!=(const TeacherId &t, const TeacherId &t2){return t2.Id()!=t.Id();}
    bool operator!=(const Teacher &t, const Teacher &t2){return t.Id()!=t2.Id() || t.Name()!=t2.Name() || t.Department()!=t2.Department();}
    std::size_t operator*(TeacherId tea, size_t val){return tea.Id()*val;}
    struct TeacherHash {
       std::size_t operator()(Teacher const &teacher1) const
       {
           std::size_t h1 = std::hash<std::string>{}(teacher1.Name());
           std::size_t h2 = std::hash<std::string>{}(teacher1.Department());
           return (teacher1.Id()*h1+h2);
       }
    };

}



#endif //JIMP_EXERCISES_TEACHERHASH_H
