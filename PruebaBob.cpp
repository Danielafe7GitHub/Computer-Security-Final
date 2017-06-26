//
// Created by pokelover on 25/06/17.
//

#include "BOBServer.h"

int main()
{
    system("python3 socket/server.py");
    readhelloClient();
    cin.get();
    system("python3 socket/client.py");
    serverHello();
    cin.get();
    intercambioClaves();
}