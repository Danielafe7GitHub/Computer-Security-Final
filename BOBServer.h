#ifndef _BOBServer
#define _BOBServer

#include <iostream>
#include <fstream>
#include "diffieHellman.h"

using namespace std;

ZZ masterKey;

/*Alice envía File Hello: Lista de Algoritmos*/
void serverHello()
{
    ofstream serverHello;
    serverHello.open("documento.txt" , std::ofstream::trunc);
    serverHello<<"B"<<endl;
    serverHello<<"Hola Alice: Algoritmo Predeterinado: Cesar"<<endl;
    serverHello.flush();
    serverHello.close();

}


void readhelloClient()
{
    string leerClient;
    ifstream clientHello;
    clientHello.open("documento.txt");
    string a;
    clientHello.seekg(0,clientHello.beg);
    getline(clientHello,a);
    while(a=="B")
    {
        clientHello.seekg(0,clientHello.beg);
        getline(clientHello,a);
    }
    while(getline(clientHello,a))
    {
        cout<<a<<endl;
    }
    clientHello.close();
}


void intercambioClaves()
{
    masterKey = sujetoNoGeneraParametros(); /*Se generó .txt de claves diffieHellman*/
}



#endif