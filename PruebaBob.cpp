//
// Created by pokelover on 25/06/17.
//

#include "BOBServer.h"

int main()
{
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
    decifrado.open("documento.txt");
    string decipher;
    getline(decifrado,decipher);
    Cesar cesar(masterKey);
    cout << cesar.decipher(decipher) << endl;
}