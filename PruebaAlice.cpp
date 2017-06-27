//
// Created by pokelover on 25/06/17.
//

#include "Alice.h"

int main()
{
    clientHello();
    if(system("python3 socket/client.py"));
    cout<<"Saludé"<<endl;
    if(system("python3 socket/server.py"));
    readhelloServer();
    intercambioClaves();
    Cesar cesar(masterKey);
    ofstream cifrado;
    cifrado.open("documento.txt" , std::ofstream::trunc);
    cifrado<<cesar.cipher("Desde este momento todo lo que diga sera cifrado");
    cifrado.close();
    if(system("python3 socket/client.py"));
}

