//
// Created by agnieszka on 31.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>
namespace pool
{
    class TextPool
    { public:
        TextPool();
        TextPool(const std::initializer_list<std::string> &words):set_of_string(words)
        {
            for ( std::initializer_list<std::string>::iterator it=words.begin(); it!=words.end(); ++it) //iterator do listy inicjalizacyjnej
            {
                std::string tmp=*it; //przypisuje stringa z words do tymcasowego
                auto search = set_of_string.find(tmp); //szukam czy sie string w zbiorze nie powtarza
                if(search != set_of_string.end())
                {
                     ptr.emplace_back(*search); //jeśli powtarza to ustawiam uchwyt na powtarzający się element
                }
                else
                {
                     ptr.emplace_back(tmp); //ustawiam uchwyt
                }
            }


            this->sz=set_of_string.size();
        };
        //TextPool(const TextPool &m); konstruktor kopiujący
        //TextPool &operator=(const TextPool &m); operator przypisania kopiujący - w zadaniu ma ich nie być
        TextPool(TextPool &&m); //konstruktor przenoszący
        TextPool &operator=(TextPool &&m); //operator przypisania przenoszący
        ~TextPool(); //destruktor
        std::experimental::string_view Intern(const std::string &str); //funkcja wstawiająca stringa do zbioru i zwracajaca uchwyt
        size_t StoredStringCount() const; //rozmiar zbioru
    private:
        size_t sz;
        std::set<std::string> set_of_string; //zbiór
        std::vector<std::experimental::string_view> ptr; //wektor z uchwytami
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
