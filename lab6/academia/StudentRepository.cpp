//
// Created by Kinga on 04.04.2017.
//

#include "StudentRepository.h"


namespace academia {

    void StudyYear::operator++()
    {
        SetY(GetY()+1);
    }
    void StudyYear::operator--()
    {
        SetY(GetY()-1);
    }

    bool Student::operator==(Student s2) const
    {
        if(this->year==s2.year && this->first_name==s2.first_name && this->id==s2.id && this->last_name==s2.last_name && this->program==program) return true;
        else return false;
    }

    Student Student::operator[](std::string given_id)
    {
        Student Student_1;
        if(this->id==given_id)
        {
            Student_1.program=this->program;
            Student_1.last_name=this->last_name;
            Student_1.id=this->id;
            Student_1.first_name=this->first_name;
            Student_1.year=this->year;
            return Student_1;
        }
        else std::cout<<"brak id";
        return Student_1;
    }

    istream& operator>>(istream & input, Student& p){

        return input;      // Umożliwia cin >> a >> b >> c;
    }

    istream &operator>>(istream &input, StudyYear &p) {
        return input;
    }

    int StudyYear::GetY() const {
        return y;
    }

    void StudyYear::SetY(int y) {
        this->y=y;
    }


    StudyYear::StudyYear(int y) : y(y) {}

    bool StudyYear::operator<(StudyYear y_2) const
    {
        if(this->y<y_2.y) return true;
        else return false;
    }

    bool StudyYear::operator>(StudyYear y_2) const
    {
        if(this->y>y_2.y) return true;
        else return false;
    }

    bool StudyYear::operator==(StudyYear y_2) const
    {
        if(this->y==y_2.y) return true;
        else return false;
    }

    bool StudyYear::operator!=(StudyYear y_2) const
    {
        if(this->y!=y_2.y) return true;
        else return false;
    }

    StudyYear::operator int() const {

        return y;
    }

};