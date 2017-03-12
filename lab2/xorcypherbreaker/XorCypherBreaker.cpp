//
// Created by Kinga on 12.03.2017.
//

#include "XorCypherBreaker.h"

using namespace std;

string nextkey(string key) //generuje "nastepny" klucz, np dostaje "stres" i zwraca "stret"
{
    int length = key.length();

    while (key[length-1]=='z')
    {
        key[length-1]='a';
        length--;
    }

    if (length==0)
    {
        return ""; //zwraca nielegalny klucz jak to juz koniec kluczy
    }
    key[length-1]++;

    return key;
}

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary)
{
    string key, bestkey;
    vector <char> decrypted;
    string word;
    int wordcount=0, maxwc=0;

    word="";

    for (int i=0; i<key_length; i++)
    {
        key+='a'; //"pierwszy" klucz
    }

    do // pętla idąca po kluczach, skonczy sie jak dostanie nielegalny klucz
    {
        wordcount=0;

        for (int i=0; i<cryptogram.size(); i++) // deszyfrowanie danym kluczem
        {
            decrypted.push_back(cryptogram[i]^key[i%key_length]); //^ to xor
        }

        for (int i=0; i<decrypted.size(); i++) //szukanie słów i szukanie ich w słowniku
        {
            if(decrypted[i]==' ' || decrypted[i]==',' || decrypted[i]=='.') //szukanie "oddzielaczy" słow
            {
                if (find(dictionary.begin(),dictionary.end(),word) != dictionary.end())
                {
                    wordcount++; //liczenie ile slow odszyfrowanych jest w slowniku
                }
                word="";
            }
            else
            {
                word+=decrypted[i];
            }
        }

        if (wordcount>maxwc) //jesli aktualny klucz jet lepszy niz ten dotychczas najlepszy, to go zamien
        {
            maxwc=wordcount;
            bestkey=key;
        }

        decrypted.clear();

        key = nextkey(key);
    }while(key!="");

    // CHRYSTE PANIE TO DZIAŁA

    return bestkey;
}