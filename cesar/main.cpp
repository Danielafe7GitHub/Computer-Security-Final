#include <iostream>
#include<NTL/ZZ.h>

using namespace NTL;
using namespace std;

class Cesar
{
public:
    ZZ clave;
    string alfabeto;
    Cesar(ZZ c)
    {
        alfabeto="abcdefghijklmnopqstuvxyz ABCDEFGHIJKLMNOPQSTVXYZ_-.,{}():1234567890";
        clave=c;
    }
    string cipher(string texto)
    {
        string cifrado="";
        for (int i=0;i<texto.size();i++)
        {
            int temp=(alfabeto.find(texto[i])+conv<int>(clave))%alfabeto.size();
            cifrado+=alfabeto[temp];


        }
            cout<<cifrado<<endl;
        return cifrado;

    }
    string decipher(string texto)
    {
        string descifrado="";
        for (int i=0;i<texto.size();i++)
        {
            int temp=(alfabeto.find(texto[i])-conv<int>(clave))%alfabeto.size();
            descifrado+=alfabeto[temp];


        }
         cout<<descifrado<<endl;
        return descifrado;

    }
};


int main()
{
    ZZ c1(3);
    Cesar c(c1);
    string d=c.cipher("hola");

    c.decipher(d);


    return 1;
}
