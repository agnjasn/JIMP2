//
// Created by Kinga on 04.04.2017.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <iostream>
using std::string;
namespace academia {

    class StudyYear
    {
    public:
        StudyYear(int y=1);

        int GetY() const;
        void SetY(int y);
        void operator++();
        void operator--();
        bool operator<(StudyYear y_2) const;
        bool operator>(StudyYear y_2) const;
        bool operator==(StudyYear y_2) const;
        bool operator!=(StudyYear y_2) const ;
        operator int() const;
    private:
        int y;
    };

    class Student
    {
    public:
        bool operator==(Student s2) const;
        Student operator[](std::string given_id);
        friend StudyYear;
    private:
        string id;
        string first_name;
        string last_name;
        string program;
        StudyYear year;
    };



};


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
