//
// Created by agnieszka on 18.04.17.
//

#include "Counts.h"
namespace datastructures
{

    Counts::Counts() {
        counts_=0;
    }

    int Counts::Get() const
    {
        return counts_;
    }

    void Counts::Set(int a)
    {
        counts_=a;
    }

    Counts::Counts(int val) {

        counts_=val;
    }

    bool Counts::operator==(Counts other) const {
        if(this->counts_==other.counts_)
            return true;
        else return false;
    }

    Counts& Counts::operator++() {

        counts_=counts_+1;
        return *this;
    }

    Counts Counts::operator+(int a)
    {
        return Counts(counts_+a);
    }

    Counts::operator int() const
    {
        return counts_;
    }

    bool Counts::operator<(Counts other) const {
        if(this->counts_<other.counts_) return true;
        else return false;
    }

    bool Counts::operator>(Counts other) const {
        if(this->counts_<other.counts_) return true;
        else return false;
    }

}