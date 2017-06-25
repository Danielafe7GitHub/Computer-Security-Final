#include <iostream>
#include<fstream>
#include"gamal.h"

#include"RSA.h"


using namespace std;
/*euclides mejorado
euclides extendido mejorado
fermata
teorema del resto chino
*/
int main()
{
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


    cout<<g.descifrar(cifrado)<<endl;
   return 0;
}
