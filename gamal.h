#ifndef GAMAL_H
#define GAMAL_H
#include<NTL/ZZ.h>
#include "libreria.h"
#include<bits/stdc++.h>
using namespace NTL;
using namespace std;


class gamal
{
    public:
    ZZ p,e1,e2;
       gamal();
        void emisor_gamal(int n_bit);
        void receptor_gamal(ZZ,ZZ,ZZ);
        ZZ resto_chino(ZZ);
        ZZ Generador(ZZ number);
        void generar_claves();
        string cifrar(string);
        string descifrar(string);
    protected:
        string alfabeto;

    private:
        int n_bites;
        ZZ k_pr;
        ZZ r;
        ZZ C1,Km;
};
gamal::gamal()
{
  
}

void gamal::emisor_gamal(int n_bit)
{
alfabeto="abcdefghijklmnopqrstuvxyz ABCDEFGHIJKLMNOPQRSTVXYZ_-.,{}():1234567890*";
    n_bites=n_bit;
    generar_claves();
     ofstream ficheroSalida;
     ficheroSalida.open ("directorios de Claves.txt");
     ficheroSalida <<"e1:"<<e1<<endl;
     ficheroSalida <<"e2:"<<e2<<endl;
     ficheroSalida <<"p:"<<p<<endl;
     ficheroSalida.close();
     ofstream f;
     /*f.open ("directorios de claves propio.txt");
     f <<"e1:"<<e1<<endl;
     f<<"e2:"<<e2<<endl;
     f<<"p:"<<p<<endl;
     f<<"d:"<<k_pr<<endl;
     ficheroSalida.close();*/
}
void gamal::receptor_gamal(ZZ P,ZZ E1,ZZ E2)
{
alfabeto="0123456789 abcdefghijklmnopqrstuvwxyz.,ABCDEFGHIJKLMNOPQRSTUVWXYZ*";

   this->p=P;
   this->e1=E1;
   this->e2=E2;
   this-> r=RandomBits_ZZ(256);
   this->C1=expMod(e1,r,p);
   this->Km=expMod(e2,r,p);
}
ZZ gamal::Generador(ZZ number)
{
    ZZ phi,result,tmp;
    bool bandera;

    phi=phi-ZZ(1);
    tmp=number-1;//Phi(number);
    Vec<ZZ> factores_phi=factoriza(phi);
    for(ZZ a=number/2-ZZ(1); a>ZZ(1);a--)///SOLO SI ES PRIMO Elementos son todos
             {   bandera=1;
                 for(int i=0;bandera!=0&&i<factores_phi.length();i++)
                 {
                    if(expMod(a,tmp/factores_phi[i],number)!=1){bandera=1;}
                    else{bandera=0;}
                 }
                 if (bandera==1)
                    return a;
             }
}
void gamal::generar_claves()
{  ZZ p1,a;
    GenPrime(p1,n_bites);
    this->p=p1;
   // GenPrime(a,n_bites/2);
   this->e1=Generador(p);
   this->k_pr=RandomBits_ZZ(n_bites-(n_bites/3));
   this->e2=expMod(e1,k_pr,p);

}
string gamal::cifrar(string mensaje)
{
        /*ZZ  C1=expMod(e1,r,p);
        ZZ  Km=expMod(e2,r,p);*/
        string pos_sig=Int_a_string(alfabeto.size()-1),str_pos;
        string msm_en_Numeros="",tmp;
        int MsPos,dif_0;
        for(int i=0;i<mensaje.size();i++)
        {  //tmp=mensaje.at(i);
            MsPos=alfabeto.find(mensaje[i]);//busco c/d letra en el alfabeto
           str_pos=Int_a_string(MsPos);
           dif_0=pos_sig.size()-str_pos.size();
           if(dif_0!=0)
               {str_pos=completar(str_pos,dif_0);}
           msm_en_Numeros=msm_en_Numeros+str_pos;
        }
        //cout<<"mensajeen numeros :"<<msm_en_Numeros<<endl;
        string Tn=ZZ_a_string(p),bloque,pedasos,cipher_msm;
          ZZ blok;
          int aux,dife,pos_W=alfabeto.find('*');
          aux=modulo(msm_en_Numeros.size(),Tn.size()-1);
          //cout<<"aux:"<<aux<<endl;
          while (aux!=0)
          {
              msm_en_Numeros=msm_en_Numeros+Int_a_string(pos_W);
              aux=modulo(msm_en_Numeros.size(),Tn.size()-1);
          }
          //cout<<"mensajeen numeros con basurita:"<<msm_en_Numeros<<endl;
        //cifrado en bloques
        for(int i=0;i<msm_en_Numeros.size();i=i+(Tn.size()-1))
            {bloque=msm_en_Numeros.substr(i,Tn.size()-1);
             // cout<<"tamaño del bloque:"<<bloque.size()<<endl;
             blok=string_a_ZZ(bloque);
             blok=modulo(blok,p)*Km;
             blok=modulo(blok,p);
             pedasos=ZZ_a_string(blok);
             dife=Tn.size()-pedasos.size();
             if(dife!=0)
                {pedasos=completar(pedasos,dife);}
             cipher_msm=cipher_msm+pedasos;
            }
        string n_c1=ZZ_a_string(C1),cipher_2;
        int t;
        t=(Tn.size())-n_c1.size();
        if (t!=0)
          {
           n_c1=completar(n_c1,t);
          }
            cipher_2=n_c1+cipher_msm;
            /*ofstream fs;
            fs.open("cifradoc1.txt");
            fs<<cipher_2;
            fs.close();*/
return cipher_2;
}


string gamal::descifrar(string cipher)
{
    string Tn=ZZ_a_string(p),c1;
    ZZ iKM;
    c1=cipher.substr(0,Tn.size());
   this->C1=string_a_ZZ(c1);
    cout<<"c1:"<<C1<<endl;
    cipher=cipher.substr(Tn.size(),cipher.size()-Tn.size());
  this->Km=expMod(C1,k_pr,p);
  iKM=inversa(Km,p);

  string blo,pedasito,msm;
  ZZ evaluar;
  int tmp;
  //cout<<"cipher:"<<cipher<<endl;
  for(int i=0;i<cipher.size();i=i+Tn.size())
    {  blo=cipher.substr(i,Tn.size());
       //cout<<"bloque dentro del descifrado:"<<blo<<endl;
       evaluar=string_a_ZZ(blo);
       evaluar=evaluar*iKM;
       evaluar=modulo(evaluar,p);
       //evaluar=expon1(evaluar,D,N);
       pedasito=ZZ_a_string(evaluar);
       tmp=(Tn.size()-1)-pedasito.size();
       if(tmp!=0)
       {
          pedasito=completar(pedasito,tmp);
       }
       msm=msm+pedasito;
    }
  string letter_sig=Int_a_string(alfabeto.size()-1);
  string sub_msm,mensaje;
  int tmp1;
   for(int i=0;i<msm.size();i=i+letter_sig.size())
   {  sub_msm=msm.substr(i,letter_sig.size());
      tmp1=string_a_int(sub_msm);
      mensaje=mensaje+alfabeto[tmp1];
   }

  return mensaje;

}

#endif // GAMAL_H
