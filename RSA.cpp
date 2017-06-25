#include "RSA.h"
#include "libreriaRSA.h"

RSA::RSA(int n_b)//constructor para el receptor el que genera sus propias claves
{
    this->bits=n_b;
     generar_claves();
     ofstream ficheroSalida;
     ficheroSalida.open ("directorios de Claves.txt");
     ficheroSalida <<"e:"<<E<<endl;
     ficheroSalida <<"N:"<<N<<endl;
     //ficheroSalida<<"D:"<<D<<endl;
     ficheroSalida.close();
     ofstream f;
     f.open ("directorios de claves propio.txt");
     f <<"e:"<<E<<endl;
     f<<"N:"<<N<<endl;
     f<<"D:"<<D<<endl;
     ficheroSalida.close();

}
RSA::RSA(ZZ e,ZZ n)//segundo constructor para el que va a cifrar.
{    this->E=e;
     this->N=n;
     //cout<<"RECEPTOR:"<<"E: "<<E<<"N:"<<N<<endl;
}
void RSA::generar_claves()//genera las claves este sirve para el primer constructor que indica con cuantos  bits va a trabajar
{ ZZ p1,q1,fi_n,e1;

  GenPrime(p1,bits/2);
  GenPrime(q1,bits/2);

  //this->P=17;
  //this->Q=59;
  this->P=p1;this->Q=q1;
  this->N=P*Q;
  fi_n=(P-1)*(Q-1);

  //e1=3;//RandomBits_ZZ(bits-(bits/3));
  while(euclides(e1,fi_n)!=1)
    {e1=RandomBits_ZZ(bits-(bits/3));}
  this->E=e1;//e1;//e1;
  this->D=inversa(E,fi_n);
}
ZZ RSA::resto_chino(ZZ base)// c^d mod n
{ ZZ dp,dq,PM,P1,P2,q1,q2,Resul;
     dp=modulo(D,P-1);
     dp=expon1(modulo(base,P),dp,P);
     dq=modulo(D,Q-1);
     dq=expon1(modulo(base,Q),dq,Q);
     //115^3(mod 11)
     //115^7(mod 13);
   PM=P*Q;// PM=11*13=143
   P1=PM/P;// P1=143/11=13
   P2=PM/Q;// P2=143/13=11
   q1=modulo(inversa(modulo(P1,P),P)*1,P);//q1=P1^-1*(1) mod P
   q2=modulo(inversa(modulo(P2,Q),Q)*1,Q);
   Resul=modulo(dp*P1*q1,PM)+modulo(dq*P2*q2,PM);
   Resul=modulo(Resul,PM);
   return Resul;

}

 string RSA::cifrar(string mensaje)
{    //capturando letra por letra convirtiendo el mensaje en numeros
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
       // cout<<"mensaje en numeros:"<<msm_en_Numeros<<endl;
        //dividir l mensaje en bloques
          string Tn=ZZ_a_string(N),bloque,pedasos,cipher_msm;
          ZZ blok;
          int aux,dife;
          /*aux=msm_en_Numeros.size()-(msm_en_Numeros.size()/(Tn.size()-1))*(Tn.size()-1);
          aux=(Tn.size()-1)-aux;*/
          aux=modulo(msm_en_Numeros.size(),Tn.size()-1);
          //cout<<"aux"<<aux<<endl;
          if(aux!=0)
          {
              aux=Tn.size()-1-aux;
              while(aux>0)
              {msm_en_Numeros=msm_en_Numeros+"0";
                aux=aux-1;//aqui cambie para que la basura sea w ( aux--;)
              }
          }
        for(int i=0;i<msm_en_Numeros.size();i=i+(Tn.size()-1))
            {bloque=msm_en_Numeros.substr(i,Tn.size()-1);
             blok=string_a_ZZ(bloque);
             blok=expon1(blok,E,N);
             pedasos=ZZ_a_string(blok);
             dife=Tn.size()-pedasos.size();
             if(dife!=0)
                {pedasos=completar(pedasos,dife);}
             cipher_msm=cipher_msm+pedasos;
            }
 return cipher_msm;
}

string RSA::descifrar(string cipher)
{//cout<<"cipher_dentro del descifar:"<<cipher<<endl;
 string Tn=ZZ_a_string(N),blo,pedasito,msm;
  ZZ evaluar;
  int tmp;
    for(int i=0;i<cipher.size();i=i+Tn.size())
    {  blo=cipher.substr(i,Tn.size());
       //cout<<"bloque dentro del descifrado:"<<blo<<endl;
       evaluar=string_a_ZZ(blo);
       evaluar=resto_chino(evaluar);
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
