//
// Created by pokelover on 25/06/17.
//

#include "BOBServer.h"

int main(){
    string challenge= "Desde este momento todo lo que diga sera cifrado";
    if(system("python3 socket/server.py"));
    readhelloClient();
    cin.get();
    serverHello();
    if(system("python3 socket/client.py"));
    cin.get();
    intercambioClaves();
    if(system("python3 socket/client.py"));

    if(system("python3 socket/server.py"));
    ifstream entrada;
    ofstream salida;
    entrada.open("documento.txt");
    string aux;
    getline(entrada,aux);
    entrada.close();
    Cesar cesar(masterKey);
    salida.open("documento.txt",std::ofstream::trunc);
    if ( cesar.decipher(aux) == challenge){
        cout << "-> " <<cesar.decipher(aux) << endl;
        salida << cesar.cipher(challenge)<< endl;
        salida.flush();
        salida.close();
        if(system("python3 socket/client.py"));
    } else{
        salida << "Comunicacion fallida! " << endl;
        salida.flush();
        salida.close();
        cout << "Comunicacion fallida! " << endl;
        cout << "Bye, bye!! " << endl;
        if(system("python3 socket/client.py"));
        return 1;
    }

}