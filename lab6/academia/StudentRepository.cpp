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