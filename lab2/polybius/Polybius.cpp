//
// Created by agnieszka on 12.03.17.
//
#include "Polybius.h"
using namespace std;

string PolybiusCrypt(string message)
{
    string crypted_word= "";
    map<char, string> crypt= {{'a',"11"}, {'b',"12"}, {'c',"13"}, {'d',"14"},
                           {'e',"15"}, {'f',"21"}, {'g',"22"}, {'h',"23"},
                           {'i',"24"}, {'j',"24"}, {'k',"25"}, {'l',"31"},
                           {'m',"32"}, {'n',"33"}, {'o',"34"}, {'p',"35"},
                           {'q',"41"}, {'r',"42"}, {'s',"43"}, {'t',"44"},
                           {'u',"45"}, {'v',"51"}, {'w',"52"}, {'x',"53"},
                           {'y',"54"}, {'z',"55"}};
    for(int i=0; i<message.length(); i++)
   {
    if(message[i]==' ') i++;
       if(message[i]<=90){message[i]+=32;}
       crypted_word+=crypt[message[i]];
    }
    return crypted_word;
}
string PolybiusDecrypt(string crypted)
{
    string message="";
    char crypt[5][5]={{'a','b','c','d','e'},
                      {'f','g','h','i','k'},
                      {'l','m','n','o','p'},
                      {'q','r','s','t','u'},
                      {'v','w','x','y','z'}};

    for(int i=0; i<crypted.length(); i+=2)
    {
        int licz1=static_cast<int>(crypted[i])-49;
        int licz2=static_cast<int>(crypted[i+1])-49;
        message+=crypt[licz1][licz2];
    }
    return message;
}