//
// Created by pokelover on 25/06/17.
//

#include "libreria.h"

vector<unsigned int> S;
vector<unsigned int> K;
vector<char> key;


class RC4
{
public:
    string llave;
    RC4(){};
    void KRC4(string clave){
        llave=clave;
    };
    ~RC4(){};

void KSA()
{

    int j=0,auxi;
    for (int i=0;i<256;i++)
    {
        j=(j+S[i]+(int)key[i%key.size()])%256;
        auxi=S[j];
        S[j]=S[i];
        S[i]=auxi;
    }

}

void PRGA()
{
    int a=0,b=0,auxi;
    for (int i=0;i<256;i++)
    {
        a=(a+1);
        b=(b+S[a])%256;
        auxi=S[a];
        S[a]=S[b];
        S[b]=auxi;
        K[i]=S[(S[a]+S[b])%256];
    }
}

void RC4_init()
{
    S.resize(256);
    K.resize(256);
    for(int i=0;i<256;i++)
    {
        S[i]=i;
    }
    key.resize(llave.size());
    for(int i=0;i<key.size();i++)
    {
        key[i]=llave[i];
    }
    KSA();
    PRGA();
}

string RC4_cypher(string text)
{
    RC4_init();
    string auxiliar="";
    int message[text.size()];
    for (int i=0;i<text.size();i++)
    {
        message[i]=(int)text[i];
    }
    int ixor;
    char buffer[2];
    for (int i=0;i<text.size();i++)
    {
        ixor=K[i]^message[i];
        dec_to_hex(buffer,ixor);
        auxiliar+=buffer[0];
        auxiliar+=buffer[1];
    }
    cout <<"RC4 cifrado: " <<auxiliar << endl;
    return auxiliar;
}

string RC4_decypher(string cypher)
{
    RC4_init();
    int ixor;
    string auxiliar="",aiuda;
    int decypher[cypher.size()/2];
    for (int i=0;i<cypher.size()/2;i++)
    {
        aiuda=cypher.substr(i*2,2);
        if(aiuda=="00"){}
        else
        {
            decypher[i]=hex2dec(aiuda);
        }
    }
    for(int i=0;i<cypher.size()/2;i++)
    {
        ixor=decypher[i]^K[i];
        char aux=ixor;
        auxiliar+=aux;
    }
    return auxiliar;
}
};/*
int main()
{
    cout<<"Ingrese clave"<<endl;
    string clave;
    cin>>clave;
    cout<<"Ingrese mensaje"<<endl;
    string mess;
    cin>>mess;
    cout<<"mensaje: "<<mess<<endl;
    cout<<RC4_cypher(mess)<<endl;
    cout<<RC4_decypher(RC4_cypher(mess))<<endl;

}*/