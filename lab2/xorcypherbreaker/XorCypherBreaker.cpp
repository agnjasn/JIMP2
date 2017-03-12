//
// Created by Kinga on 12.03.2017.
//

#include "XorCypherBreaker.h"

using namespace std;

string nextkey(string key)
{
    int length = key.length();

    while (key[length-1]=='z')
    {
        key[length-1]='a';
        length--;
    }

    if (length==0)
    {
        return "";
    }
    key[length-1]++;

    return key;
}

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary)
{
    string key, ki;
    vector <char> decrypted;
    string word;
    int wordcount=0, maxwc=0;

    word="";

    for (int i=0; i<key_length; i++)
    {
        key+='a';
    }

    do // pętla idąca po kluczach
    {
        wordcount=0;

        for (int i=0; i<cryptogram.size(); i++) // deszyfrowanie danym kluczem
        {
            decrypted.push_back(cryptogram[i]^key[i%key_length]);
        }

        for (int i=0; i<decrypted.size(); i++) //szukanie słów i szukanie ich w słowniku
        {
            if(decrypted[i]==' ' || decrypted[i]==',' || decrypted[i]=='.')
            {
                if (find(dictionary.begin(),dictionary.end(),word) != dictionary.end())
                {
                    wordcount++;
                }
                word="";
            }
            else
            {
                word+=decrypted[i];
            }
        }

        if (wordcount>maxwc)
        {
            maxwc=wordcount;
            ki=key;
        }

        decrypted.clear();

        key = nextkey(key);
    }while(key!="");

    // CHRYSTE PANIE TO DZIAŁA

    return ki;
}