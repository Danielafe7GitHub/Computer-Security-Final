#include <NTL/ZZ.h>
#include <iostream>

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

void AliceBob(ZZ prime, ZZ random)
{
    pair<ZZ,ZZ> clavesAliceBob = generacionClave(prime,random);
    ZZ privateKey = clavesAliceBob.first;
    ZZ publicKey = clavesAliceBob.second;
    ZZ publicKeyBob;

    cout<<"Tu clave Publica es: "<<publicKey<<endl;
    cout<<"Ingrese la  Clave Publica de su Companiero: ";cin>>publicKeyBob;

    /* Calcula la clave secreta común*/
    ZZ KAB = PowerMod(publicKeyBob,privateKey,prime);
    cout<<"Su clave en Comun es:  "<<KAB<<endl;

}

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

    

}
