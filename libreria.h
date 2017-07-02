#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED
#include <string>
#include<bits/stdc++.h>
#include <vector>
#include<stdlib.h>
#include<math.h>
#include <NTL/ZZ.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace NTL;



using namespace std;
using namespace NTL;
//ZZ funcion;

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
/*
ZZ euclides(ZZ x,ZZ y)//(250,111)
{ ZZ  cociente,r;
  while(y>0)//111>0
   {
    cociente=x/y;//q=250/111=2...q=111/28=3........q=28/27=1...q=27/1
    r=x-cociente*y;//r=250-2*111=28..r=111-3*28=27..r=1........r=0
    x=y;//x=111..............x=28............x=27.......x=1
    y=r;//y=28...............y=27............y=1........y=0
    }
return x;
}*/

ZZ euclides(ZZ a, ZZ b)
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
/*
ZZ Euclides_Binario(ZZ u, ZZ v)
{
    ZZ g(1),t;
    ZZ a=abs(u);ZZ b=abs(v);
    while modulo(a,2)==0 && modulo(b,2)==0
    {   a=a>>1;
        b=b>>1;
        g=2*g;
    }
    while a>0
    {    if modulo(a,2)==0 a=a>>2;
         else if  modulo(b,2)==0  b=b>>2;
         else {
              t=abs(a-b)>>1;
              if a>=b  a=t;
              else b=t;
         }
    }
}*/
vector<ZZ> Binary_extendedEuclidean(ZZ x,ZZ y)
{
    vector<ZZ> l;
    ZZ a,b;
    ZZ u,v,A,B,C,D;
    int g=1;
    while((x&1)==0 and (y&1)==0){
            x=x>>1; y=y>>1;  g=2*g;}
            u=x;  v=y; A=1; B=0; C=0; D=1;
    while(u!=0){
    while((u&1)==0)
    {
        u=u>>1;
        if((A&1)==0 and (B&1)==0){
            A=A>>1; B=B>>1;}
        else{
            A=(A+y)>>1; B=(B-x)>>1;}

    }
    while((v&1)==0)
    {
        v=v>>1;
        if((C&1)==0 and (D&1)==0){
            C=C>>1; D=D>>1;}
        else{
            C=(C+y)>>1; D=(D-x)>>1;}

    }
    if(u>=v){
        u=u-v; A=A-C; B=B-D;}
    else{
        v=v-u; C=C-A; D=D-B;}
    }

        l.push_back(C);
        l.push_back(D);
        l.push_back(g*v);
  return l;
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
string ZZ_a_string(ZZ n)
{
stringstream  ss;
ss<<n;
string  numero;
ss>>numero;
return numero;
}
string  binari(ZZ a)
{ //vector<bool> nm;
    string binario;
while(a>0)
    {
     binario=ZZ_a_string(modulo(a,ZZ(2)));
     a=a>>1;
    }
   return binario;
}
ZZ ExpoBin(ZZ a,string b,ZZ c)
{ ZZ c1(0);
  ZZ d(1);
  for(int i=b.size()-1;i>=0;i--)
    {
         c1=2*c1;
         d=modulo(d*d,c);
         if(b[i]=='1')
         {
            c1=c1+1;
            d=modulo(d*a,c);
         }
    }
  return d;
}
template<class Y>
Y expo_binari(Y a,Y k,Y n)
{  //numero en binario
    string K=binario(k);
    reverse(K.begin(),K.end());//************
Y b(1),A;
if(k==0)return b;
A=a;
if((K[0]-'0')==1) b=a;
for(int i=1;i<K.size();i++)
    {
      A=modulo_y(A*A,n);
      if((K[0]-'0')==1)b=modulo_y(A*b,n);
    }
    return b;
}

ZZ expMod(ZZ  a, ZZ p, ZZ n)
	{
	ZZ  y;
	y = ZZ(1);
	while (p!=ZZ(0))
	{
      if ((p&1)==1)
		y = modulo((y * a) ,n);

      a = modulo((a * a),n);
      p = p >> 1;
	}

	return y;
}
string corrimiento_derecha(string cifra)
{string aux;
        aux=cifra[cifra.size()-1]+cifra.substr(0,cifra.size()-2);
        return aux;
}
string corrimiento_izquierda(string cifra)
{string aux;
        aux=cifra.substr(1,cifra.size()-2)+cifra[1];
        return aux;
}

vector<ZZ> euclides_extendido(ZZ x,ZZ  y)
{
 vector<ZZ >  G;
  ZZ r(0),q(0),i;
ZZ  t1(0),t2(1),t,s1(1),s2(0),s;
while(y>0)
{
    q=x/y;
    r=x-q*y;
    i=x=y;
    y=r;
    s=s1-q*s2;
    s1=s2;
    s2=s;
    t=t1-q*t2;
    t1=t2;
    t2=t;

}
s=s1;
t=t1;
G.push_back(s);
G.push_back(t);
G.push_back(i);
return G;
}

ZZ inversa(ZZ  a, ZZ  b)
{   vector<ZZ>  v;
    ZZ inver;
    v=Binary_extendedEuclidean(a,b);
    if(v[2]==1)
        {inver=v[0];
        if(inver<0 or inver>b )
            inver=modulo(inver,b);}
    else
        {cout<<"no tine inversa"<<endl;}
return  inver;
}
template<class T>
bool MILLER(T p,T iteration)
{
    //cout<<"entro a miller"<<endl;
    ZZ z=conv<ZZ>("2");
    if (p < 2)
        return 0;///Elimina el 1 ya que no es primo
    if (p != 2 && modulo(p,z)==0)///Por la segunda ccondicion acepta el 2
        return 0;///Termina en numeros pares
    ZZ s;
    s = p - 1;
    while (modulo(s,z)==0){
        s>>=1;//s /= 2;
    }
    ZZ a , mod , temp , mods;
    SetSeed(ZZ(INIT_VAL, time(NULL)));///semilla
    //out<<"w_M"<<endl;
    for (long i = 0; i < iteration; i++)
    {
        a = RandomBnd(p-1);
        temp = s;
        mod = expon1(a, temp, p);
        //cout<<":";
        while ((temp!=p-1)&&(mod!=1)&&(mod!=p-1)){
            ///mods=MODULO(mod*mod,p);
            //cout<<"-:-";
            mod=MULMOD(mod,mod,p);
            temp<<=1;
        }
        if ((mod!=p-1)&&(modulo(temp,z)==0))
            return 0;
    }
    //system("pause");
    return 1;
}
bool Miller ( ZZ p ,int iteration)
 {

 ZZ s;
 sub(s,p,ZZ(1));

  while ( modulo(s, ZZ(2)) == 0)
     {
         s=RightShift(s,1);}
         ZZ a;
         ZZ temp;
         ZZ modu;
         ZZ pmenos;
         sub(pmenos,p,ZZ(1));
         a=2;
  for (int i = 0; i < iteration ; i ++)
     {
         temp = s;
         modu = expMod(a, temp , p);
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
ZZ inversa_multiplicativa(ZZ a,ZZ b)
{ ZZ result;
    if (Miller(b,1000))
        result=expMod(a,b-2,b);
    return result;
}
//***********************EXTRA PARA RSA******************************************
template<class var>
string binario(var numero)
{string num;
   do{num+='0'+(numero&1);
     }
     while(numero>>=1);
     reverse(num.begin(),num.end());
     return num;

}
string Int_a_string(int a)
{
    stringstream stream;
    stream<<a;
    string b=stream.str();
    return b;
}
string Rellenar_zeros_adelante(string num,int cant)
{
    //string Msj;
    int tam=num.size();
    while(tam<cant){
            num.insert(0,"0");
        tam++;
    }
   return num;
}
string completar(string name,int a)
{while(a>0)
         {name.insert(0,"0");
         a=a-1;}
    return name;
}
template<class T>
T string_a_T(string algo)
{stringstream sst(algo);
 T Num;
 sst>>Num;
 return Num;
}
ZZ string_a_ZZ(string algo)///verdadero funciona (anabel)
{stringstream sst(algo);
 ZZ Num;
 sst>>Num;
 return Num;
}
int string_a_int(string n)
{
 stringstream ss(n);
 int numero;
 ss>>numero;
 return numero;
}
vector<int> calc_primes(const int max)
{
  vector<int> sieve;
  vector<int> primes;

  for (int i = 1; i < max + 1; ++i)
     sieve.push_back(i);   // you'll learn more efficient ways to handle this later
  sieve[0]=0;
  for (int i = 2; i < max + 1; ++i) {   // there are lots of brace styles, this is mine
     if (sieve[i-1] != 0) {
        primes.push_back(sieve[i-1]);
        for (int j = 2 * sieve[i-1]; j < max + 1; j += sieve[i-1]) {
            sieve[j-1] = 0;
        }
     }
  }

    return primes;
}
//**********************
vector<ZZ> criba_m(int m,int n)
{

cout << (int)sqrt(n) << endl;
vector<int> p=calc_primes((int)sqrt(n));
    //int a=sqrt(n);
    //cout<<"a:"<<a<<endl;
int mini=(m+1-3);
mini = mini>>1;
int maxi=(n-3);
maxi = maxi>>1;
//int tam = maxi-mini;
bool primo[n];
int np=p.size();


for(int j=mini;j<=maxi;j++)
{
    primo[j]=true;
}

int k,q,q2,mp;

for(int i=1;i<np;i++)
{
 if (m<=p[i]^2)
     {
       k=(p[i]-1)>>1;
       while((2*k+1)*p[i]<=n)
       {
           primo[((2*k+1)*p[i]-3)>>1]=false;
           k=k+1;
       }
     }
 if((p[i]^2)<m)
 {
   q=(m-1)/p[i];
   q2=modulo(q,2);
   k=q2;
   mp=(2*k+1-q2+q)*p[i];

   while(mp<=n) {

     primo[(mp-3)>>1]=false;
     k=k+1;
     mp=(2*k+1-q2+q)*p[i];
   }
 }
}

vector<ZZ> pri;
cout<<"estoy en la criba"<<endl;
for(int j=mini;j<=maxi;j++)
    {   cout<<"hello"<<endl;
         if(primo[j]==true)
         {
             cout<<"holaaa:"<<(2*j+3)<<endl;
           ZZ a=conv<ZZ>(2*j+3);
           pri.push_back(a);
            //cout<<"  "<<2*j+3<<endl;
         }
   }

for(int j=mini;j<=maxi;j++)
    {
         cout<<"hello"<<endl;
         if(primo[j]==true)
         {
             cout<<"holaaa:"<<(2*j+3)<<endl;

            //cout<<"  "<<2*j+3<<endl;
         }
   }
return pri;
}










int  string_a_numero(string numero)
{
         int value = atoi (numero.c_str ());
        return value;
}
int modulo(int a,int n)//(-255,11)
{  int  q1,r;
         q1=a/n;//-255=11(-23);hallando (-23);
         r=a-q1*n;//-255=11(-23)-2;hallando residuo=(-2)
         if(r<0)//(-2)<0
            {r=n+r;//11+(-2);
             q1=q1-1;//(-23)-1;
             }
    return r;//11+(-2)=9
}
template<class T>
string num_en_base(T nume,int base)
{
    string tmp,rpt;
    tmp=binario(nume);
    int t;
    t=modulo(tmp.size(),base);
    if(t>0)
    {
       rpt=completar(tmp,base-t);
    }
    else{rpt=tmp;}
  return rpt;
}
int bin_to_decimal(string bin)/// Conversion de Binario a Decimal
{
    int numero(0);
    long tam=bin.length();
    for(long i=0;i<tam;i++){
        numero<<=1;
        numero|=(bin[i]&1)?1:0;///or binario
    }
    return numero;
}






// GENERADOR DE RAICES PRIMITIVAS
Vec<ZZ> factoriza(ZZ n)
{
    ZZ i;
    Vec<ZZ> Factores;
    i=ZZ(2);
    while(n>ZZ(1))
    {   if(modulo(n,i)==ZZ(0))
        {  n=n/i;
           Factores.append(i);
           i=ZZ(2);
        }
        else
            i++;
    }
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





///RC4

string toHex(int number){
    string aux[6]={"A","B","C","D","E","F"};
    if( number > 9 )
        return aux[number-10];
    return to_string(number);
}

void dec_to_hex(char*buffer,int number)
{
    long int decimalNumber,remainder,quotient;
    int i=1,j,temp;
    char hexadecimalNumber[100];

    decimalNumber=number;

    quotient = decimalNumber;

    while(quotient!=0)
    {
        temp = quotient % 16;

        //To convert integer into character
        if( temp < 10)
            temp =temp + 48;
        else
            temp = temp + 55;

        hexadecimalNumber[i++]= temp;
        quotient = quotient / 16;
    }
    int p=0;
    if(i==2)
    {
        buffer[0]='0';
        p=1;
    }
    for(j = i -1 ;j> 0;j--)
    {
        buffer[p]=hexadecimalNumber[j];
        p++;
    }
    return;
}

int hex2dec(string hex)
{
    int result = 0;
    for (int i=0; i<hex.length(); i++) {
        if (hex[i]>=48 && hex[i]<=57)
        {
            result += (hex[i]-48)*pow(16,hex.length()-i-1);
        } else if (hex[i]>=65 && hex[i]<=70) {
            result += (hex[i]-55)*pow(16,hex.length( )-i-1);
        } else if (hex[i]>=97 && hex[i]<=102) {
            result += (hex[i]-87)*pow(16,hex.length()-i-1);
        }
    }
    return result;
}


#endif // LIBRERIA_H_INCLUDED

