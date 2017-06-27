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
    ifstream decifrado;
    ofstream algo;
    decifrado.open("documento.txt");
    string decipher;
    getline(decifrado,decipher);
    decifrado.close();
    Cesar cesar(masterKey);

    if ( cesar.decipher(decipher) == challenge){
        algo.open("documento.txt",std::ofstream::trunc);
        algo << cesar.cipher(challenge)<< endl;
    } else{
        cout << "Comunicacion fallida! " << endl;
        cout << "Bye, bye!! " << endl;
        return 1;
    }

}