//
// Created by agnieszka on 12.03.17.
//

#include "Polybius.h"
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
    string message="";
    string crypted="";
    string pliktekst=argv[1];
   string plikszyfr=argv[2];
    int wybor=atoi(argv[3]);
    if(wybor==1)                                //szyfrowanie
    {
        ifstream openfile(pliktekst.c_str());
        if(openfile.good())
        {
            while (!openfile.eof()) {          //aż dojdzie do końca pliku
                getline(openfile, message);    //bierze całą linie <do znaku \n> i wstawia do message
            }
            openfile.close();
        }
        else cout<<"blad przy otwieraniu";
        crypted=PolybiusCrypt(message);

        ofstream sendtofile("plik-szyfr.txt");
        if(sendtofile.good())
        {
            sendtofile << crypted;
            sendtofile.close();
        }
        else cout<<"blad przy zamykaniu";
    }
    else if(wybor==0)                          //odszyfrowanie
    {
        ifstream openfile(plikszyfr.c_str());
        if(!openfile) cout<<"blad";
        while (!openfile.eof())
        {
            getline(openfile, crypted);
        }
        openfile.close();

        message=PolybiusDecrypt(crypted);

        ofstream sendtofile(pliktekst.c_str());
        if(sendtofile.good())
        {
            sendtofile << message;
            sendtofile.close();
        }
        else cout<<"blad przy zamykaniu";
    }
    else cout<<"bledne polecenie";            //zabezpieczenie jakby argv[3] był inny niz 0 lub 1
    return 0;
}