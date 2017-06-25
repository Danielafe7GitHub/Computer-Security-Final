//
// Created by jhoelccari on 11/06/17.
//

#ifndef COMPUTER_SECURITY_FINAL_FUNMATEMATICAS_H
#define COMPUTER_SECURITY_FINAL_FUNMATEMATICAS_H

#include <NTL/ZZ.h>

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace NTL;

int num_bits;

template<class F>
F modulo(F a,F  n)//(-255,11)
{  F  q1,r;
         q1=a/n;//-255=11(-23);hallando (-23);
         r=a-q1*n;//-255=11(-23)-2;hallando residuo=(-2)
         if(r<0)//(-2)<0
            {r=n+r;//11+(-2);
             q1=q1-1;//(-23)-1;
             }
    return r;//11+(-2)=9
}



ZZ expon1(ZZ a,ZZ b,ZZ c)
{
    ZZ exp(1);
    ZZ x=modulo(a,c);

    while(b>0)
    {
      if(modulo(b,to_ZZ(2))==1)
        {exp=modulo(exp*x,c);}
      x=modulo(x*x,c);
      b=b>>1;
    }
    return exp;
}




  vector<ZZ>binario(ZZ num)
{
    vector<ZZ>binarios;
    //int base=2;
    ZZ base=ZZ(2);
        while(num>=2)
        {
            binarios.insert(binarios.begin(),modulo(num,base));
            num=num>>1;
        }
        binarios.insert(binarios.begin(),num);

        return binarios;
}




/////////////////////////////

ZZ exponenciacionModular()
{

}


ZZ expo(ZZ a, ZZ l, ZZ n)
{
    vector<ZZ>k=binario(l); int t=k.size();
    reverse(k.begin(),k.end());
    ZZ b=ZZ(1);

    if ( l==0) return b;
    ZZ A=a;
    if (k[0]==1) b=a;
    for(int i=1; i<t;i++)
    {
     A=modulo_Z(A*A,n);
    // if(mod(l,2)==0) return A;
     if (k[i]==1) b=modulo_Z(A*b,n);

    }

    return b;
}


////////////////////////////////////////////////////////

ZZ generadorAleatorios()
{
}

ZZ plantar_semilla()
{

    ZZ semilla,result;
    semilla=RandomBnd(100000);
    semilla++;
    return semilla;

}
vector<ZZ> completar_sets()
{
    ZZ contador_set;
    ZZ num=plantar_semilla();
    contador_set=ZZ(num_bits)-NumBits(num);//diferencia num_bits global y los bits de la semilla
    vector<ZZ>vector_binario;
    vector_binario=binario(num);//binario de la semila
    ZZ set_x;
    long i;
    for(i=0;i<contador_set;i++)
    {
        set_x=modulo_Z((vector_binario[i]+vector_binario[i+1]),ZZ(2));
        vector_binario.push_back(set_x);

    }

    return vector_binario;
}

vector<ZZ>XOR()
{
    vector<ZZ>binarito_set;
    binarito_set=completar_sets();
    int vueltas=100;///4096
    ZZ first_element;
    long t=binarito_set.size();
    srand(time(0));
    int pos_tap;
    pos_tap=RandomBnd(t);
    ZZ tap=binarito_set[pos_tap];

    for(int i=0;i<vueltas;i++)
    {
        first_element=binarito_set[0];

        long j;
        for( j=0;j<binarito_set.size()-1;j++)
        {
            binarito_set[j]=binarito_set[j+1];

        }
       binarito_set[binarito_set.size()-1]= (first_element^ tap);

    }
    ///Le cambiare el ultimo bit simepre a 1 para que sea impar u tiemda a primo
    binarito_set[t-1]=1;


    return binarito_set;

}


ZZ convert_to_decimal()///GENERA EL ALEATORIO EN DECIMAL
{
    vector<ZZ> numero;
    numero=XOR();
    ZZ num_decimal;
    long base=2;
    num_decimal=0;
    long tam=numero.size()-1;
    long i;
    for( i=0; i<=tam;i++)
    {
        if(numero[i]==1)
        {
            num_decimal+=power_ZZ(base,tam-i);
        }
    }
    //si es multiplo de 5 lo paso
    ZZ cinco=ZZ(5);
    ZZ cero=ZZ(0);
    if(modulo(num_decimal,cinco)==cero)
    {
        num_decimal=num_decimal+2;
    }
    return num_decimal;
}




ZZ generadorPrimos()
{
}



///-------------------------TEST DE PRIMALIDAD MILLER RABIN
bool Miller ( ZZ p, int iteration )
 {

 ZZ s;
 sub(s,p,ZZ(1));

  while ( modulo(s, ZZ(2)) == 0)
     {
         s=RightShift(s,1);}// /2

         ZZ a;
         ZZ temp;
         ZZ modu;
         ZZ pmenos;
         sub(pmenos,p,ZZ(1));

         a=ZZ(29);//876495974718971929854696543789087654536789087654678908765435678976);//aleatorio BUEN NUMERO
  for (int i = 0; i < iteration ; i ++)
     {
         temp = s;
         modu = expo(a, temp , p);
         while ( temp != pmenos    &&      modu != ZZ(1)     &&     modu != pmenos)
             {
                modu = modulo((modu*modu) ,p);
                temp= LeftShift(temp,1);
             }

         if (modu != pmenos && modulo(temp ,ZZ(2))== 0)
             {

                return false ;
             }
         }

     return true ;
 

}





Vec<ZZ> Primos(int num)
{
    ///ALEATORIO
    ZZ result;
    result=convert_to_decimal();
    ///cout<<result<<endl;
   // bool miller= x.Miller(result,2);

    ///GENERA PRIMO ALEATORIO
    ZZ a;
    Vec<ZZ> resultados;
    a= ZZ(2); //mejor mas 2 porque el aleatorio es impar (mejoras de Dani) quiza 4 sea un mejor numero ya que reduce mas rapido o algun multiplo de 2
  int f=0;
   while (f<num)
    {
        //result=x.convert_to_decimal();
        sub(result,result,a);//Mejor que sea menos porque no tiende a crecer sino a disminuir y el test se hara de un numero menor
        if(Miller(result,1)==1)//SI ES PRIMO
        {
         resultados.append(result);
         f+=1;
         /*cout <<endl;
         cout<<"PRIMOTE:  "<<endl;
         cout<<result<<endl;*/
        }

        //x.Miller(result,1);
    }
   return resultados;
}







ZZ MCD()
{
}
ZZ algoritmo_euclides_menor_resto(ZZ a, ZZ b)///MCD
{
    ZZ c;
    ZZ d;
    ZZ r;
    if(a==to_ZZ ("0"))
    {c=b;}
    else{

    c=a;
    d=b;
    while(d!=to_ZZ ("0"))
    { ZZ srem=c/d+to_ZZ ("1")/to_ZZ ("2");
    r=c-d*srem;
    //if(c-d<0) r=r*(-1);//valor absoluto srem
    c=d;
    d=r; }
    }
    if(c<to_ZZ ("0")) c=c*(to_ZZ ("-1"));//valor absoluto
    return c;
}





void factorizacion()
{

}

Vec<ZZ> factoriza(ZZ n)
{
    ZZ i;
    Vec<ZZ> Factores;
    i=ZZ(2);
    while(n>ZZ(1))
    {   if(modulo_Z(n,i)==ZZ(0))
        {  n=n/i;
           Factores.append(i);
           i=ZZ(2);
        }
        else
            i++;
    }
    /*for(int i=0;i<Factores.length();i++)
    {
        cout<<"FACTORES: "<<Factores[i]<<endl;
    }*/
    return Factores;

}

ZZ Phi(ZZ number)
{ZZ phi;
 phi=ZZ(1); ///SI ES PRIMO SOLO RESTA
     if(Miller(number,1)==true) {
        phi=number-ZZ(1);
        return phi;
     }
     else{
         Vec<ZZ> factores=factoriza(number);
         for(int cont=0; cont<factores.length();cont++)
         {
             factores[cont]=factores[cont]-ZZ(1);
         }
         for(int cont=0; cont<factores.length();cont++)
         {
             phi*=factores[cont];
         }
         return phi;
     }
}



void swap(){

}

void cambioBase(){

}

#endif //COMPUTER_SECURITY_FINAL_FUNMATEMATICAS_H
