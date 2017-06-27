//
// Created by pokelover on 25/06/17.
//

#include "Alice.h"
#include "tools.h"

vector<string> algorythms {"RSA","RC4,3DES","ElGamal","GHOST"};
vector<string> match;
vector<int> secuencia;


int main()
{

    ///HANDSHAKE CLIENTE
    ofstream salida;
    ifstream entrada;
    string challenge="Desde este momento todo lo que diga sera cifrado";
    string aux;
    clientHello();
    if(system("python3 socket/client.py"));
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
    ///TERMINA HANDSHAKE

    ///NEGOCIACIÓN DE ALGORITMOS
    salida.open("documento.txt",std::ofstream::trunc);
    for (int i=0;i<algorythms.size();i++)
    {
        salida<<cesar.cipher(algorythms[i])<<endl;
    }
    salida.flush();
    salida.close();
    if(system("python3 socket/client.py"));
    if(system("python3 socket/server.py"));

    entrada.open("documento.txt");
    match=recopilar(cesar);
    cout<<"Algoritmos compartidos:"<<endl;
    for(int i=0;i<match.size();i++)
    {
        cout<<match[i]<<endl;
    }
    if(system("python3 socket/server.py"));
    vector<string> auxiliar;
    auxiliar=recopilar(cesar);
    for(int i=0;i<auxiliar.size();i++)
    {
        secuencia.push_back(stoi(auxiliar[i]));
    }
    cout<<"Secuencia de algoritmos"<<endl;
    for(int i=0;i<secuencia.size();i++)
    {
        cout<<match[i]<<"->"<<secuencia[i]<<endl;
    }

    //192.168.199.9
}

