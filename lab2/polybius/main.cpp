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
    if(wybor==1)
    {
        ifstream openfile(pliktekst.c_str());
        if(openfile.good())
        {
            while (!openfile.eof()) {
                getline(openfile, message);
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
    else if(wybor==0)
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
        if(!sendtofile) cout<<"blad";
        sendtofile<<message;
        sendtofile.close();
    }
    else cout<<"bledne polecenie";
    return 0;
}