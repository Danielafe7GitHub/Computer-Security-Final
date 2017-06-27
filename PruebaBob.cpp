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

    if ( cesar.decipher(aux) == challenge){
        salida.open("documento.txt",std::ofstream::trunc);
        salida << cesar.cipher(challenge)<< endl;
        salida.flush();
        if(system("python3 socket/client.py"));
    } else{
        cout << "Comunicacion fallida! " << endl;
        cout << "Bye, bye!! " << endl;
        return 1;
    }

}