#include <NTL/ZZ.h>
#include <iostream>
#include <fstream>
#include <string>
#include "libreria.h"
#include <unistd.h>

using namespace std;
using namespace NTL;

pair<ZZ,ZZ> publicarClaves()
{
    /*Escoger un primo grande p :Publicarlos*/
    ZZ prime = RandomPrime_ZZ(10, 100);
    ZZ random = RandomBnd(prime);
    pair<ZZ,ZZ> retorno = make_pair(prime,random);
    return retorno;
}


pair<ZZ,ZZ> generacionClave(ZZ prime, ZZ random)
{
    /*Escoger una clave Privada*/
    ZZ privateKey =  RandomBnd(prime);

    /*Calcular la Clave Pública*/
    ZZ publicKey = PowerMod(random,privateKey,prime);

    pair<ZZ,ZZ> retorno = make_pair(privateKey,publicKey);
    return retorno;

}

pair<ZZ,ZZ> AliceBob(ZZ prime, ZZ random)
{
    pair<ZZ,ZZ> clavesAliceBob = generacionClave(prime,random);
    ZZ privateKey = clavesAliceBob.first;
    ZZ publicKey = clavesAliceBob.second;
    ZZ publicKeyBob;
/*
    cout<<"Tu clave Publica es: "<<publicKey<<endl;
    cout<<"Ingrese la  Clave Publica de su Companiero: ";cin>>publicKeyBob;
*/
    /* Calcula la clave secreta común*/
/*    ZZ KAB = PowerMod(publicKeyBob,privateKey,prime);
    cout<<"Su clave en Comun es:  "<<KAB<<endl;
*/

    /*Generando txt Diffie Hellman*/
    ofstream clavesPublicasDiffieHellman;
    clavesPublicasDiffieHellman.open("documento.txt",std::ofstream::trunc);
    clavesPublicasDiffieHellman<<"A"<<endl;
    clavesPublicasDiffieHellman<<prime<<endl;
    clavesPublicasDiffieHellman<<random<<endl;
    clavesPublicasDiffieHellman<<publicKey<<endl;
    clavesPublicasDiffieHellman.flush();
    clavesPublicasDiffieHellman.close();
    cout<<"Puse claves"<<endl;
    if(system("python3 socket/client.py"));
    return make_pair(prime,privateKey);
}

ZZ MasterKeyAlice(pair<ZZ,ZZ> par)
{
    /* Calcula la clave secreta común*/
    ifstream doc;
    string bob,a;
    ZZ bobkey;
    if(system("python3 socket/server.py"));
    doc.open("documento.txt");
    doc.seekg(0,doc.beg);
    getline(doc,a);
    while(a=="A")
    {
        doc.seekg(0,doc.beg);
        //cout<<"pos: "<<doc.tellg()<<endl;
        getline(doc,a);
        //doc.seekg(0,doc.beg);
        //cout<<"pos: "<<doc.tellg()<<endl;
        usleep(3000);
    }
    getline(doc,bob);
    cout<<"Bob: "<<bob<<endl;
    getline(doc,bob);
    bobkey=string_a_ZZ(bob);
    cout<<bobkey<<" y "<<par.second<<" y "<<par.first<<endl;
    ZZ KAB = PowerMod(bobkey,par.second,par.first);
    cout<<"Su clave en Comun es:  "<<KAB<<endl;
    doc.close();
    return KAB;
}


ZZ BobAlice(ZZ prime, ZZ random, ZZ alice)
{
    pair<ZZ,ZZ> clavesAliceBob = generacionClave(prime,random);
    ZZ privateKey = clavesAliceBob.first;
    ZZ publicKey = clavesAliceBob.second;
    //ZZ publicKeyBob;
    ofstream docu;
    docu.open("documento.txt", std::ofstream::trunc);
    docu<<"B"<<endl;
    docu<<publicKey;
    docu.flush();
    docu.close();

    /* Calcula la clave secreta común*/
    ZZ KAB = PowerMod(alice,privateKey,prime);
    cout<<"Su clave en Comun es:  "<<KAB<<endl;

    return KAB;

}
pair<ZZ,ZZ> sujetoGeneraParametros()
{
    pair<ZZ,ZZ> clavesPublicas = publicarClaves();
    return AliceBob(clavesPublicas.first,clavesPublicas.second);

}

ZZ sujetoNoGeneraParametros()
{
    ZZ prime,random,pubAlice;
    string praim, ramdom, alice,a;
    if(system("python3 socket/server.py"));
    cout<<"Ya llegó el paquete"<<endl;
    cin.get();
    ifstream doc;
    doc.open("documento.txt");
    doc.seekg(0,doc.beg);
    getline(doc,a);
    while(a=="B")
    {
        doc.seekg(0,doc.beg);
        getline(doc,a);
    }
    getline(doc,praim);
    getline(doc,ramdom);
    getline(doc,alice);
    prime=string_a_ZZ(praim);
    random=string_a_ZZ(ramdom);
    pubAlice=string_a_ZZ(alice);
    cout<<prime<<endl;
    cout<<random<<endl;
    cout<<pubAlice<<endl;
    doc.close();
    ZZ masterKey = BobAlice(prime,random,pubAlice);
    return masterKey;
}



/*
int main()
{


    loop:

    int opcion;
    cout<<" -------Hola Ingrese La Opcion que le Corresponde "<<endl;
    cout<<"  Si es Usted Quien Genera los Parametros Ingrese <<1>> "<<endl;
    cout<< "********************************"<<endl;
    cout<<"  Si es Usted Quien  NO Genera los Parametros Ingrese <<2>> "<<endl;
    cout<< "********************************"<<endl;

    cin>>opcion;
    if(opcion==1)
    {
        pair<ZZ,ZZ> clavesPublicas = publicarClaves();
        cout<<"El primo generado es: "<<clavesPublicas.first<<endl;
        cout<<"El Random generado es: "<<clavesPublicas.second<<endl;
        AliceBob(clavesPublicas.first,clavesPublicas.second);
    }
    if(opcion==2)
    {
        ZZ prime,random;
        cout<<"Ingrese el Primo generado: ";cin>>prime;
        cout<<"Ingrese el Random generado: ";cin>>random;
        AliceBob(prime,random);
    }



}*/

