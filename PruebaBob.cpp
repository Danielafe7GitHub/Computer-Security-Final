//
// Created by pokelover on 25/06/17.
//

#include "BOBServer.h"
#include "tools.h"
#include "g_rsa.cpp"
vector<string> algorythms{"RSA","RC4,3DES","FEISTEL","CESAR","ElGamal"};
//vector<string> algorithms2{"RSA","asdfFEISTEL","CESAR","3DES","ElGamal"};
vector<string> match;
vector<int> secuencia;


int main() {
    /// HANDSHAKE INICIO
    string challenge = "Desde este momento todo lo que diga sera cifrado";
    if (system("python3 socket/server.py"));
    readhelloClient();
    serverHello();
    if (system("python3 socket/client.py"));
    intercambioClaves();
    if (system("python3 socket/client.py"));
    if (system("python3 socket/server.py"));
    ifstream entrada;
    ofstream salida;
    entrada.open("documento.txt");
    string aux;
    getline(entrada, aux);
    entrada.close();
    Cesar cesar(masterKey);
    cout << "Clave cesar :" << cesar.clave << endl;
    salida.open("documento.txt", std::ofstream::trunc);
    cout << "auxiliar " << aux << endl;
    cout << "-> " << cesar.decipher(aux) << endl;
    if (cesar.decipher(aux) == challenge) {

        salida << cesar.cipher(challenge) << endl;
        salida.flush();
        salida.close();
        if (system("python3 socket/client.py"));
    } else {
        salida << "Comunicacion fallida! " << endl;
        salida.flush();
        salida.close();
        cout << "Comunicacion fallida! " << endl;
        cout << "Bye, bye!! " << endl;
        if (system("python3 socket/client.py"));
        return 1;
    }
    /// HANDSHAKE FIN

    /// NEGOCIACION INICIO
    if (system("python3 socket/server.py"));
    entrada.open("documento.txt");
    match = recopilar(cesar);
    match = matchingAlgoritmos(algorythms, match);
    salida.open("documento.txt", std::ofstream::trunc);
    cout << "Algoritmos compartidos:" << endl;
    for (int i = 0; i < match.size(); i++) {
        salida << cesar.cipher(match[i]) << endl;
        cout << match[i] << endl;
    }
    salida.flush();
    salida.close();
    if (system("python3 socket/client.py"));

    if (system("python3 socket/server.py"));
    secuencia = serie(match);
    salida.open("documento.txt", std::ofstream::trunc);
    cout << "Secuencia Algoritmos compartidos:" << endl;
    for (int i = 0; i < secuencia.size(); i++) {
        salida << cesar.cipher(to_string(secuencia[i])) << endl;
        cout << secuencia[i] << endl;
    }
    salida.flush();
    salida.close();

    if (system("python3 socket/client.py"));
    cout << " despues de secuencia" << endl;
    ///GENERACION DE CLAVES SIMETRICAS
    cout << "masterKey: " << masterKey << endl;
    tdeskey(masterKey);
    cout << " despues de secuencia 1" << endl;

    rc4key(deskey);
    cout << " despues de secuencia 2" << endl;
    cout<<"Clave RC4: "<<rckey<<endl;
    ///GENERACION DE CLAVES ASIMETRICAS PUBLICAS
    rsaemisor.emisor_RSA(256);
    gemisor.emisor_gamal(256);
    if(system("python3 socket/server.py"));

    vector<string> publicKeys = recopilar(cesar);

    rsareceptor.receptor_RSA(string_a_ZZ(publicKeys[0]),string_a_ZZ(publicKeys[1]));
    greceptor.receptor_gamal(string_a_ZZ(publicKeys[4]),string_a_ZZ(publicKeys[2]),string_a_ZZ(publicKeys[3]));

    salida.open("documento.txt",std::ofstream::trunc);
    salida<<cesar.cipher(ZZ_a_string(rsaemisor.E))<<endl;
    salida<<cesar.cipher(ZZ_a_string(rsaemisor.N))<<endl;
    salida<<cesar.cipher(ZZ_a_string(gemisor.e1))<<endl;
    salida<<cesar.cipher(ZZ_a_string(gemisor.e2))<<endl;
    salida<<cesar.cipher(ZZ_a_string(gemisor.p))<<endl;
    salida.flush();
    salida.close();
    if(system("python3 socket/client.py"));


    //192.168.199.19

}