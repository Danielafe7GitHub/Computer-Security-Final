#ifndef Alice
#define Alice

#include <iostream>
#include <fstream>
#include "diffieHellman.h"

using namespace std;
ZZ masterKey;

/*Alice envía File Hello: Lista de Algoritmos*/
void clientHello()
{
    ofstream clientHello;
    clientHello.open("documento.txt" , std::ofstream::trunc);
    clientHello<<"A"<<endl;
    clientHello<<"Hola Bob: Algoritmo Predeterminado: Cesar."<<endl;
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



#endif