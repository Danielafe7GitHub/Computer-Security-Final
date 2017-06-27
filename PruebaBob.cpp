//
// Created by pokelover on 25/06/17.
//

#include "BOBServer.h"
#include "tools.h"
vector<string> algorythms{"RSA","RC4","FEISTEL","CESAR","3DES","ElGamal"};
//vector<string> algorithms2{"RSA","asdfFEISTEL","CESAR","3DES","ElGamal"};
vector<string> match;

int main(){
    /// HANDSHAKE INICIO
    string challenge= "Desde este momento todo lo que diga sera cifrado";
    if(system("python3 socket/server.py"));
    readhelloClient();
    serverHello();
    if(system("python3 socket/client.py"));
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
    cout << "auxiliar " << aux << endl;
    cout << "-> " <<cesar.decipher(aux) << endl;
    if ( cesar.decipher(aux) == challenge){

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
    /// HANDSHAKE FIN

    /// NEGOCIACION INICIO
    if(system("python3 socket/server.py"));
    entrada.open("documento.txt");
    match=recopilar(entrada);
    match=matchingAlgoritmos(match,algorythms);
    salida.open("documento.txt",std::ofstream::trunc);
    cout<<"Algoritmos compartidos:"<<endl;
    for (int i=0;i<algorythms.size();i++)
    {
        salida<<algorythms[i]<<endl;
        cout<<algorythms[i]<<endl;
    }
    salida.flush();
    salida.close();
    if(system("python3 socket/client.py"));

    //192.168.1.104

}