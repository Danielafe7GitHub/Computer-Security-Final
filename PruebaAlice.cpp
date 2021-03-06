//
// Created by pokelover on 25/06/17.
//

#include "Alice.h"
#include "tools.h"
#include "g_rsa.cpp"
#include "libreria.h"

vector<string> algorythms {"RC4,3DES","RSA","ElGamal","GHOST"};
vector<string> match;
vector<int> secuencia;



int main() {


    ///HANDSHAKE CLIENTE
    ofstream salida;
    ifstream entrada;
    string challenge = "Desde este momento todo lo que diga sera cifrado";
    string aux;
    clientHello();
    if (system("python3 socket/client.py"));
    if (system("python3 socket/server.py"));
    readhelloServer();
    intercambioClaves();
    Cesar cesar(masterKey);
    salida.open("documento.txt", std::ofstream::trunc);
    salida << cesar.cipher(challenge);
    salida.close();
    if (system("python3 socket/client.py"));
    if (system("python3 socket/server.py"));
    entrada.open("documento.txt");
    getline(entrada, aux);
    entrada.close();
    if (cesar.decipher(aux) == challenge) {
        cout << "Comunicación iniciada correctamente, proceda a negociar" << endl;
    } else {
        cout << "Comunicación fallida" << endl;
        return 1;
    }
    ///TERMINA HANDSHAKE

    ///NEGOCIACIÓN DE ALGORITMOS
    salida.open("documento.txt", std::ofstream::trunc);
    for (int i = 0; i < algorythms.size(); i++) {
        salida << cesar.cipher(algorythms[i]) << endl;
    }
    salida.flush();
    salida.close();
    if (system("python3 socket/client.py"));
    if (system("python3 socket/server.py"));

    entrada.open("documento.txt");
    match = recopilar(cesar);
    cout << "Algoritmos compartidos:" << endl;
    for (int i = 0; i < match.size(); i++) {
        cout << match[i] << endl;
    }
    if (system("python3 socket/client.py"));
    salida.open("documento.txt", std::ofstream::trunc);
    salida << "OK" << endl;
    salida.flush();
    salida.close();
    if (system("python3 socket/server.py"));
    vector<string> auxiliar;
    auxiliar = recopilar(cesar);
    for (int i = 0; i < auxiliar.size(); i++) {
        secuencia.push_back(stoi(auxiliar[i]));
    }
    cout << "Secuencia de algoritmos" << endl;
    for (int i = 0; i < secuencia.size(); i++) {
        cout << match[i] << "->" << secuencia[i] << endl;
    }

    ///GENERACION DE CLAVES SIMETRICAS
    tdeskey(masterKey);
    rc4key(deskey);
    cout << "Clave RC4: " << rckey << endl;
    ///GENERACION DE CLAVES ASIMETRICAS PUBLICAS
    rsaemisor.emisor_RSA(64);
    gemisor.emisor_gamal(64);
    salida.open("documento.txt", std::ofstream::trunc);
    salida << cesar.cipher(ZZ_a_string(rsaemisor.E)) << endl;
    salida << cesar.cipher(ZZ_a_string(rsaemisor.N)) << endl;
    salida << cesar.cipher(ZZ_a_string(gemisor.e1)) << endl;
    salida << cesar.cipher(ZZ_a_string(gemisor.e2)) << endl;
    salida << cesar.cipher(ZZ_a_string(gemisor.p)) << endl;
    salida.flush();
    salida.close();
    if (system("python3 socket/client.py"));
    cout << "EMPIEZA CIFRADO" << endl;
    if(system("python3 socket/server.py"));
    vector<string> publicKeys = recopilar(cesar);
    rsareceptor.receptor_RSA(string_a_ZZ(publicKeys[0]), string_a_ZZ(publicKeys[1]));
    greceptor.receptor_gamal(string_a_ZZ(publicKeys[4]), string_a_ZZ(publicKeys[2]), string_a_ZZ(publicKeys[3]));

    cout <<" claves RSA receptop" << endl;
    cout << rsareceptor.E << " " << rsareceptor.N << endl;

    bloques();
    string mensaje;
    while (true)
    {
        getline(cin,mensaje);
        cipher(mensaje, secuencia, match);
        //cout<<"Mensaje cifrado: "<<aux<<endl;
        /*salida.open("documento.txt",std::ofstream::trunc);
        salida<<aux;
        salida.flush();
        salida.close();*/
        if(system("python3 socket/client.py"));

        if(system("python3 socket/server.py"));
        /*entrada.open("documento.txt",std::ifstream::binary);
        aux = "";
        cout<<"puntero: "<<entrada.tellg()<<endl;
        entrada.seekg(0,entrada.beg);
        cout<<"puntero: "<<entrada.tellg()<<endl;
        while(getline(entrada,aux))
        {
            cout <<aux<<endl;
        }*/
        aux=get_file_contents("documento.txt");
        cout << "leyendo " << aux <<"."<< endl;
        cout << "Descifrado" << endl;
        cout << decifrado(aux,secuencia,match) << endl;
    }




    //192.168.199.9
    //192.168.161.82
    //192.168.199.207
    //192.168.198.53
}

