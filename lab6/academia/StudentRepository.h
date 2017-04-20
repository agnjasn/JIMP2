//
// Created by Kinga on 04.04.2017.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <iostream>
#include <sstream>
using std::string;
namespace academia {

    using std::istream;
    using std::ostream;

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
        bool operator!=(StudyYear y_2) const;


        operator int() const;
    private:
        int y;
    };

    class Student
    {
    public:
        Student operator[](std::string given_id);
        bool operator==(Student s2) const;

        friend StudyYear;
    private:
        string id;
        string first_name;
        string last_name;
        string program;
        StudyYear year;
    };

    istream& operator>>(istream & input, StudyYear& p);
    istream& operator>>(istream & input, Student& p);

};


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
