//
// Created by agnieszka on 31.03.17.
//

#include "TextPool.h"
namespace pool
{
    TextPool::TextPool() {
        sz=set_of_string.size();
    }

    //konstruktor przenoszący
    TextPool::TextPool(TextPool &&m) {
        set_of_string.clear(); //czyszcze zbiór i wektor
        ptr.clear();
        set_of_string.swap(m.set_of_string); //zamieniam zbiory specjalny swap dla set
        ptr.swap(m.ptr); //zamieniam wektory
        sz=set_of_string.size(); //ustawiam nowe rozmiary
        m.sz=m.set_of_string.size();
    }

    //operator przypisania przenoszący
    TextPool &TextPool::operator=(TextPool &&m) { //to samo co w konstruktorze oprócz if
        if (this == &m) {
            return m;
        }

        set_of_string.clear();
        ptr.clear();
        set_of_string.swap(m.set_of_string);
        ptr.swap(m.ptr);
        sz=set_of_string.size();
        m.sz=m.set_of_string.size();
    }

    TextPool::~TextPool() {

    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        auto search = set_of_string.find(str); //szukam czy sie string w zbiorze nie powtarza
        if(search != set_of_string.end())
        {
            ptr.emplace_back(*search); //jeśli powtarza to ustawiam uchwyt na powtarzający się element

        }
        else
        {
            set_of_string.emplace(str); //jak nie to dodaje stringa do zbioru
            ptr.emplace_back(str); //ustawiam uchwyt
            sz=set_of_string.size(); //zmieniam rozmiar
        }
        return ptr.back(); //zwracam uchwyt
    }

    size_t TextPool::StoredStringCount() const {
        return sz;
    }
}