//
// Created by pokelover on 25/06/17.
//

#include "Alice.h"

int main()
{
    ofstream salida;
    ifstream entrada;
    string challenge="Desde este momento todo lo que diga sera cifrado";
    string aux;
    clientHello();
    if(system("python3 socket/client.py"));
    cout<<"Saludé"<<endl;
    if(system("python3 socket/server.py"));
    readhelloServer();
    intercambioClaves();
    Cesar cesar(masterKey);
    salida.open("documento.txt" , std::ofstream::trunc);
    salida<<cesar.cipher(challenge);
    salida.close();
    if(system("python3 socket/client.py"));
    if(system("python3 socket/server.py"));
    entrada.open("documento.txt");
    getline(entrada,aux);
    entrada.close();
    if(cesar.decipher(aux)==challenge)
    {
        cout<<"Comunicación iniciada correctamente, proceda a negociar"<<endl;
    }
    else
    {
        cout<<"Comunicación fallida"<<endl;
        return 1;
    }
}

