#include <iostream>
#include<fstream>
#include"gamal.h"
#include <fstream>
#include "3DES.h"
#include "RC4.cpp"


#include"RSA.h"


using namespace std;
/*euclides mejorado
euclides extendido mejorado
fermata
teorema del resto chino
*/

gamal greceptor;
RC4 rc4;
RSA rsareceptor;
TDES des;

gamal gemisor;
RSA rsaemisor;


vector<string> readListALg()
{
    string leer;
    vector<string> ordenAlg;
    ifstream listAlg;
    listAlg.open("listaAlgoritmos.txt");
    
    while(getline(listAlg,leer))
    {
        ordenAlg.push_back(leer);
    }
    listAlg.close();
return ordenAlg;
}


string cipher()
{
     cout<<"CIPHER"<<endl;
    string key1,key2,key3,mensaje;
    cout<<"Ingrese MENSAJE para cifrar:"<<endl;
    getline(cin,mensaje);
    vector<string> ordenAlg=readListALg();

    for (int i = 0; i < ordenAlg.size(); ++i)
    {

        if(ordenAlg[i]== "3DES")
        {
             cout<<"3DES"<<endl;
            cout << "Ingrese su clave 1:";cin>>key1;
            cout << "Ingrese su clave 2:";cin>>key2;
            cout << "Ingrese su clave 3:";cin>>key3;
            cout<<endl;
            des.KTDES(key1,key2,key3);
            mensaje=des.cipher(mensaje);
            //descifrado=des.decipher(mensaje);
        }else if(ordenAlg[i]== "RSA")
        {
             cout<<"RSA"<<endl;

            ZZ E,n;
            cout<<endl;
            cout << "Ingrese su clave publica E:";cin>>E;
            cout << "Ingrese su N:";cin>>n;cout<<endl;
            cin.ignore();
            rsareceptor.receptor_RSA(E,n);
            mensaje=rsareceptor.cifrar(mensaje);
          /*  Mensaje=emisor.descifrar(cifrado);
            cout<<"\tMENSAJE ORIGINAL:\n";
            cout<<Mensaje<<endl;*/
        }else if(ordenAlg[i]== "RC4")
        {
             cout<<"RC4"<<endl;
            string llave;
            cout << "Ingrese su clave :";cin>>llave;

            rc4.KRC4(llave);
            mensaje= rc4.RC4_cypher(mensaje);
    //  cout<<rc4.RC4_decypher(RC4_cypher(mess))<<endl;

        }else if (ordenAlg[i]== "GAMAL")
        {
             cout<<"GAMAL"<<endl;


            ZZ E1,E2,P;
            cout<<endl;
            cout << "Ingrese su clave publica E1:";cin>>E1;
            cout << "Ingrese su clave publica E2:";cin>>E2;
            cout << "Ingrese su p:";cin>>P;cout<<endl;
            cin.ignore();
            greceptor.receptor_gamal(P,E1,E2);
            
            mensaje=greceptor.cifrar(mensaje);

          //  cout<<g.descifrar(cifrado)<<endl;
           

        }
    }
    
    
    return mensaje;
    
}


string decipher(string mensaje)
{
    cout<<"DECIPHER"<<endl;
    int n_bits;
    string key1,key2,key3;
    vector<string> ordenAlg=readListALg();
   for (int i = ordenAlg.size()-1;i>=0; --i)
    {
         if(ordenAlg[i]== "3DES")
        {
            cout<<"3DES"<<endl;
         
          /*  cout << "Ingrese su clave 1:";cin>>key1;
            cout << "Ingrese su clave 2:";cin>>key2;
            cout << "Ingrese su clave 3:";cin>>key3;
            cout<<endl;
            TDES des(key1,key2,key3);
            mensaje=des.cipher(mensaje);*/
            mensaje=des.decipher(mensaje);
        }else if(ordenAlg[i]==  "RSA")
        {
             cout<<"RSA"<<endl;
             cout << "Ingrese el numero de bits:";cin>>n_bits;
            rsaemisor.emisor_RSA(n_bits);


            mensaje=rsaemisor.descifrar(mensaje);

        }else if(ordenAlg[i]== "RC4")
        {
           cout<<"RC4"<<endl;

            mensaje= rc4.RC4_decypher(mensaje);
    //  cout<<rc4.RC4_decypher(RC4_cypher(mess))<<endl;

        }else if(ordenAlg[i]=="GAMAL")
        {
             cout<<"GAMAL"<<endl;
            cout << "Ingrese el numero de bits:";cin>>n_bits;
            gemisor.emisor_gamal(n_bits);
            
            mensaje=gemisor.descifrar(mensaje);

          //  cout<<g.descifrar(cifrado)<<endl;
          

        }
    }
        return mensaje;
    
}




int main()
{
ofstream listaAlgoritmos;
    listaAlgoritmos.open("listaAlgoritmos.txt");
  // listaAlgoritmos<<"3DES"<<endl;
  //  listaAlgoritmos<<"RSA"<<endl;
  //  listaAlgoritmos<<"RC4"<<endl;
  //  listaAlgoritmos<<"GAMAL"<<endl;
    listaAlgoritmos.close();

    
    string cifrado=cipher();
    cout<<"cifrado "<<cifrado<<endl;
    cout<<"descifrado "<<decipher(cifrado)<<endl;


/*
    RSA  emisor(32);
    string cifrado,mensaje;string Mensaje;
    ZZ E,n;
    cout<<endl;
    cout << "Ingrese su clave publica E:";cin>>E;
    cout << "Ingrese su N:";cin>>n;cout<<endl;
    cin.ignore();
    RSA receptor(E,n);
    cout<<"ingrese MENSAJE para cifrar:"<<endl;
    getline(cin,mensaje);
    cifrado=receptor.cifrar(mensaje);
  Mensaje=emisor.descifrar(cifrado);
    cout<<"\tMENSAJE ORIGINAL:\n";
    cout<<Mensaje<<endl;
*/




/*

    gamal  g(128);
  //  RSA r(32);

    string cifrado,mensaje;
    ZZ E1,E2,P;
	cout<<endl;
	cout << "Ingrese su clave publica E1:";cin>>E1;
	cout << "Ingrese su clave publica E2:";cin>>E2;
	cout << "Ingrese su p:";cin>>P;cout<<endl;
	cin.ignore();
	gamal receptor(P,E1,E2);
	cout<<"ingrese MENSAJE para cifrar:"<<endl;
	getline(cin,mensaje);
	cifrado=receptor.cifrar(mensaje);
    cout<<"cifrado: "<<cifrado<<endl;


    cout<<g.descifrar(cifrado)<<endl;*/
   return 0;
}
