#ifndef RSA_H
#define RSA_H
#include<iostream>
#include<NTL/ZZ.h>
#include<bits/stdc++.h>
using namespace std;
using namespace NTL;
class RSA
{
    public:
        RSA(int bits);
        RSA(ZZ,ZZ);
        ZZ resto_chino(ZZ);
        string cifrar(string);
        string descifrar(string);
        void generar_claves();



    protected:
       string alfabeto="0123456789 abcdefghijklmnopqrstuvwxyz.,ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                     //"abcdefghijklmnñopqrstuvwxyz ABCDEFGHIJKLMOPQRSTUVWXYZ0123456789.,;:-_()@{}+/";

    private:
          int bits;
        ZZ N,P,Q,E,D;
};

#endif // RSA_H
