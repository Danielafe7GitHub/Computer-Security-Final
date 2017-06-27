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
        alfabeto="abcdefghijklmnopqrstuvxyz ABCDEFGHIJKLMNOPQRSTVXYZ_-.,{}():1234567890";
        clave=c%alfabeto.size();
    }
    string cipher(string texto)
    {
        string cifrado="";
        for (int i=0;i<texto.size();i++)
        {
            int temp=(alfabeto.find(texto[i])+conv<int>(clave))%alfabeto.size();
            cifrado+=alfabeto[temp];
        }
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
        return descifrado;

    }
};


