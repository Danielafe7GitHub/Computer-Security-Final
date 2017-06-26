#include <iostream>
#include <fstream>
#include "diffieHellman.h"
#include "cesar.h"
using namespace std;
ZZ masterKey;

/*Alice envía File Hello: Lista de Algoritmos*/
void clientHello()
{
    ofstream clientHello;
    clientHello.open("documento.txt" , std::ofstream::trunc);
    clientHello<<"A"<<endl;
    clientHello<<"Hola Bob: Algoritmo Predeterminado: Cesar."<<endl;
    clientHello<<"Mis algoritmos son: RSA, Gamal, RC4, 3DES";
    clientHello.flush();
    clientHello.close();

}

void readhelloServer()
{
    string leerServer;
    ifstream serverHello;
    serverHello.open("documento.txt");
    string a;
    serverHello.seekg(0,serverHello.beg);
    getline(serverHello,a);
    while(a=="A")
    {
        serverHello.seekg(0,serverHello.beg);
        getline(serverHello,a);
        serverHello.seekg(0,serverHello.beg);
        //cout<<"espera"<<endl;
        usleep(3000);
    }
    while(getline(serverHello,a))
    {
        cout<<a<<endl;
    }
    //serverHello>>leerServer;
    serverHello.close();
}


void intercambioClaves()
{
     /*Se generó .txt de claves diffieHellman*/
    masterKey=MasterKeyAlice(sujetoGeneraParametros());
}


void writecifradoServer()
{
    /*A partir de este punto todo será cifrado*/
    Cesar cesarin (masterKey);
    string textoCifrado = cesarin.cipher("A partir de este punto todo seá cifrado. Atte: Alice");
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
