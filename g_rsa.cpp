#include <iostream>
#include<fstream>
#include"gamal.h"
#include <fstream>
#include "3DES.h"
#include "RC4.cpp"
#include<NTL/ZZ.h>
using namespace NTL;


#include"RSA.h"
#define block_size 8

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

vector<string>deskey;
string rckey;

void tdeskey(ZZ MK)
{
    cout <<"Bob en tdeskey"<<endl;
    int dMK, a = 0;
    dMK = conv<int>(MK);
    vector<string> keys;
    char buffer[2];
    string clave;
    for (int j = 0; j < 3; j++) {
        clave = "";
        int w = 0;
        do {
            //cout <<"..."<<endl;
            a += dMK % 16;
            dec_to_hex(buffer, a);
            clave += buffer[1];
            cout << clave << endl;
            w++;
        } while (w < 16);
        keys.push_back(clave);
    }
    deskey=keys;
    cout <<" termina tdesley" << endl;
    return;
}

void rc4key(vector<string> tdeskey)
{
    cout << " fucniton rc4key" << endl;
    cout << tdeskey.size() << endl;
    string key="";
    for (int i=0; i<tdeskey.size();i++)
    {
        key+=tdeskey[i];
        cout << "key: " << key << endl;
    }
    rckey=key;
}

string cipher(string mensaje,vector<int>secuencia,vector<string>match)
{
    int cant_bloques=(mensaje.size()/block_size)+1;
    while(mensaje.size()%block_size)
    {
        mensaje+='*';
        cout<<"añado basura"<<endl;
    }
    string resultado="";
    cout<<"cantidad de bloques"<<cant_bloques<<endl;
    for(int i=0;i<cant_bloques;i++)
    {
        if (match[i%match.size()]=="RSA")
        {
            cout<<"cifrado con RSA"<<endl;
            for(int j=0;j<secuencia[i];j++)
            {
                resultado+=rsaemisor.cifrar(mensaje.substr(i*8,8));
                i++;
                if(i>=cant_bloques)
                {
                    break;
                }
            }
        }
        else if (match[i%match.size()]=="RC4,3DES")
        {
            cout<<"cifrado simetrico"<<endl;
            for(int j=0;j<secuencia[i];j++)
            {
            resultado+=des.cipher(rc4.RC4_cypher(mensaje.substr(i*8,8)));
                i++;
                if(i>=cant_bloques)
                {
                    break;
                }
            }
        }
        else if (match[i%match.size()]=="ElGamal")
        {
            cout<<"cifrado con ElGamal"<<endl;
            for(int j=0;j<secuencia[i];j++)
            {
            resultado+=gemisor.cifrar(mensaje.substr(i*8,8));
                i++;
            if(i>=cant_bloques)
            {
                break;
            }
        }
        }
        cout<<resultado<<endl;
    }
    return resultado;
}

string decifrado(string mensaje, vector<int> secuencia, vector<string> match){
    int cant_bloques=(mensaje.size()/block_size)+1;
    while(mensaje.size()%block_size)
    {
        mensaje+='*';
        cout<<"añado basura"<<endl;
    }
    string resultado="";
    cout<<"cantidad de bloques"<<cant_bloques<<endl;
    for(int i=0;i<cant_bloques;i++)
    {
        if (match[i%match.size()]=="RSA")
        {
            cout<<"cifrado con RSA"<<endl;
            for(int j=0;j<secuencia[i];j++)
            {
                resultado+=rsaemisor.descifrar(mensaje.substr(i*8,8));
                i++;
                if(i>=cant_bloques)
                {
                    break;
                }
            }
        }
        else if (match[i%match.size()]=="RC4,3DES")
        {
            cout<<"cifrado simetrico"<<endl;
            for(int j=0;j<secuencia[i];j++)
            {
                resultado+=des.decipher(rc4.RC4_cypher(mensaje.substr(i*8,8)));
                i++;
                if(i>=cant_bloques)
                {
                    break;
                }
            }
        }
        else if (match[i%match.size()]=="ElGamal")
        {
            cout<<"cifrado con ElGamal"<<endl;
            for(int j=0;j<secuencia[i];j++)
            {
                resultado+=gemisor.descifrar(mensaje.substr(i*8,8));
                i++;
                if(i>=cant_bloques)
                {
                    break;
                }
            }
        }
        cout<<resultado<<endl;
    }
    return resultado;
}


/*
string cipher(string mensaje,ZZ MK)
{
     cout<<"CIPHER"<<endl;
    string key1,key2,key3,clave="",llave="";
    vector<string> keys;

    char buffer[2];
    int dMK,a=0;
    dMK=conv<int>(MK);


    vector<string> ordenAlg=readListALg();

    for (int i = 0; i < ordenAlg.size(); ++i)
    {

        if(ordenAlg[i]== "3DES")
        {
            cout<<"3DES"<<endl;
            for(int j=0;j<3;j++)
            {clave="";
            int w=0;
            do
            {
                a+=dMK%16;
                dec_to_hex(buffer,a);

                clave+=buffer[2];
                w++;
            }while(w<16);
            keys.push_back(clave);
            llave+=keys[j];
        }*/
         /* 
            cout << "Ingrese su clave 1:";cin>>key1;
            cout << "Ingrese su clave 2:";cin>>key2;
            cout << "Ingrese su clave 3:";cin>>key3;
            cout<<endl;]*/
/*
            des.KTDES(keys[0],keys[1],keys[2]);
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
            mensaje=rsareceptor.cifrar(mensaje);*/
          /*  Mensaje=emisor.descifrar(cifrado);
            cout<<"\tMENSAJE ORIGINAL:\n";
            cout<<Mensaje<<endl;*//*
        }else if(ordenAlg[i]== "RC4")
        {
             cout<<"RC4"<<endl;*/
         /*   string llave;
            cout << "Ingrese su clave :";cin>>llave;
*//*
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
         */
          /*  cout << "Ingrese su clave 1:";cin>>key1;
            cout << "Ingrese su clave 2:";cin>>key2;
            cout << "Ingrese su clave 3:";cin>>key3;
            cout<<endl;
            TDES des(key1,key2,key3);
            mensaje=des.cipher(mensaje);*/
           /* mensaje=des.decipher(mensaje);
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
    
}*/





