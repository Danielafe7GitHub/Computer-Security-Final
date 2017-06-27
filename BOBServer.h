#include <iostream>
#include <fstream>
#include "diffieHellman.h"
#include "cesar.h"
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


void writecifradoServer()
{
    /*A partir de este punto todo será cifrado*/
    Cesar cesarin (masterKey);
    string textoCifrado = cesarin.cipher("A partir de este punto todo seá cifrado. Atte: Bob");
    ofstream clientHello;
    clientHello.open("documento.txt" , std::ofstream::trunc);
    clientHello<<textoCifrado;
    clientHello.flush();
    clientHello.close();
}

void readcifradoServer()
{
    Cesar cesarin (masterKey);
    string leerServer;
    ifstream serverHello;
    serverHello.open("documento.txt");
    serverHello>>leerServer;
    serverHello.close();

    /*Descifrando a Server*/
    cesarin.decipher(leerServer);

}

