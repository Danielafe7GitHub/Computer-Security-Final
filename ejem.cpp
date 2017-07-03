#include "RSA.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
RSA e;
e.emisor_RSA(32);
RSA r;
r.receptor_RSA(e.E,e.N);
string n=r.cifrar("hola");
cout<<e.descifrar(n)<<endl;

return 1;
}
