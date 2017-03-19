//
// Created by Kinga on 14.03.2017.
//

#include "TinyUrl.h"

namespace tinyurl {

    std::unique_ptr<TinyUrlCodec> Init() {
        auto p = make_unique<TinyUrlCodec>(); //alokacja pamięci
        p->hash.fill('0'); //wypełienie licznika pierwszym stanem
        return p; //zwrócenie wskaźnika na strukturę z mapą z urlami i licznikiem do kodowania
    }

    void NextDigit(char &digit) {   //generuje kolejną "cyfrę" 0 - 9 -> A -Z -> a - z
        if (digit == '9') digit='A';
        else if (digit == 'Z') digit='a';
        else digit++;
    }

    void NextHash(std::array<char, 6> *state) {  //kolejny ten do kodowania url, aktualny stan tego to będzie skórcony url
        int i = 5;
        while ((*state)[i] == 'z') {  //idzie po tej tablicy od tyłu i dopóki widzi 'z' to zamienia na '0'
            (*state)[i] = '0'; // jak licznik jest samymi 'z'ami to się "przekręci" z powrotem na 000000
            i--;
        }
        if (i >= 0) { // jak trafi na cos innego niz 'z' to zamienia ten znak na kolejną "cyfrę"
            NextDigit((*state)[i]);  // według tego generatora 0-9A-Za-z
        }

    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec)
    {
        string tinyurl(begin((*codec)->hash), end((*codec)->hash)); //przerobienie tego licznika(?) z tej dziwnej tablicy na stringa
        (*codec)->TinyUrlMap.emplace(tinyurl, url); // zapisanie w mapie skróconego i długiego url
        return tinyurl; // zwrócenie tego zakodowanego url bo funkcja sobie tego życzy

    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash)
    {
        return codec->TinyUrlMap[hash]; //no zwrócenie długiego urla powiązanego z danym hashem
    }

}