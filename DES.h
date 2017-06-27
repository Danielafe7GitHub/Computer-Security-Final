//
// Created by jhoelccari on 11/06/17.
//

#ifndef COMPUTER_SECURITY_FINAL_DES_H
#define COMPUTER_SECURITY_FINAL_DES_H

#include <bitset>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

class CDES
{
public:
    CDES(string clave);
    void generateKey(string hex);
    string HexToBin(string t);
    string StrToAscci(string a);
    string StrToHex(string t);
    string toBinary(int v);
    string fill(string t,string fill, int n);


    string Convert64to56Bits(string t);
    string Convert56to48Bits(string t);
    string Convert32to48Bits(string binary);

    string initialPermutation(string t);
    string PermutationP(string t);
    string finalPermutation(string t);

    string leftShift(string t);
    string rightShift(string t);
    string XOR(string k, string r);
    string s(string b, int box);
    string f(string r, string k);

    long to_int2(string b);
    long to_int4(string b);

    string cipher(string plain);
    string decipher(string cipher);

    string key;
    vector<string> keys;
    //string L[17];
    //string R[17];
};

CDES::CDES(string clave)
{
    generateKey(clave);
}

void CDES::generateKey(string hex)
{
    key = HexToBin(hex);
    key = Convert64to56Bits(key);
    string c,d, aux;
    c = key.substr(0,28);
    d = key.substr(28,54);
    int shifts[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    for(int j=0; j<16; j++){
        for(int k=0; k<shifts[j]; k++){
            c = leftShift(c) ;
            d = leftShift(d) ;
        }
        aux = Convert56to48Bits(c+d);
        keys.push_back(aux);
    }
    /*
    cout <<" 16 Claves DES "<< endl;
    for(int i=0; i< keys.size(); ++i)
        cout << i+1 <<"  "<< keys[i].size()<< " " <<keys[i]<< endl;
    */
}

string CDES::StrToAscci(string a)
{
    string ascci; int tmp;
    for(int i=0; i<a.size(); i++){
        tmp = (int)a[i];
        ascci += to_string(tmp);
    }
    return ascci;
}

string CDES::s(string b, int box)
{
    int boxes[8][64]{{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13},
                     {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9},
                     {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12},
                     {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,8,12,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14},
                     {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3},
                     {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13},
                     {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12},
                     {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11} };
    string tmp1, tmp2;
    int n;
    tmp1 = b.substr(0,1)+b.substr(5,1);
    tmp2 = b.substr(1,4);
    n = boxes[box][(to_int2(tmp1)*16)+to_int4(tmp2)];
    return toBinary(n) ;
}

string CDES::f(string r, string k) //r is of 32 bits ; k is of 48 bits
{
    string f,tmp1,tmp2 ,aux;
    r = Convert32to48Bits(r);
    aux = XOR(k,r);
    for(int i=0, box=0; i<aux.size(); i+=6, box++){
        string tmp =  s( aux.substr(i,6), box);
        f+= tmp;
    }
    f = PermutationP(f);
    return f;
}
string CDES::cipher(string plain) /// plain is a text in hexadecimal
{
    //cout << "cifrado" << endl;
    string cipher;
    plain = HexToBin(plain);
    //cout <<"Plain to Binary: \n"<< plain << endl;
    plain = fill(plain,"0",64);
    long sizePlain = plain.size();
    /*	l = Ln-1	/ ls = Ln 	/ r = Rn-1 / rs = Rn 	*/
    string piece;
    string L[17];
    string R[17];
    for (int i=0,k=0; i< sizePlain ; i+=64,k++ ){
        //cout << i<< " "<< k <<" "<<64*k << " " << i+64<< endl;
        piece = plain.substr(64*k,i+64);
        piece = initialPermutation(piece);
        //cout << k << " " <<piece << endl;
        L[0] = piece.substr(0,32);
        R[0] = piece.substr(32,32);
        //cout <<" L " << L[0]<<endl;
        //cout <<" R " << R[0] << endl;
        for(int j=1; j<17 ; j++){
            L[j] = R[j-1];
            bitset<32> tmpL(L[j-1]); bitset<32> tmpR(f(R[j-1],keys[j-1]));
            R[j] = (tmpL^tmpR).to_string() ;
        }
        cipher += finalPermutation(R[16]+L[16]);
    }
    return StrToHex(cipher) ;
}

string CDES::decipher(string plain)
{
    //cout << "decifrado" << endl;
    string cipher;
    plain = HexToBin(plain);
    //cout <<"Plain to Binary: \n"<< plain << endl;
    plain = fill(plain,"0",64);
    long sizePlain = plain.size();
    /*	l = Ln-1	/ ls = Ln 	/ r = Rn-1 / rs = Rn 	*/
    string piece;
    string L[17];
    string R[17];
    for (int i=0; i< sizePlain ; i+=64 ){
        piece = plain.substr(i,i+64);
        piece = initialPermutation(piece);
        //cout << piece << endl;
        L[0] = piece.substr(0,32);
        R[0] = piece.substr(32,32);
        for(int j=1; j<17 ; j++){
            //cout <<" ----------------- " << j << " -------------------"<< endl;
            L[j] = R[j-1];
            bitset<32> tmpL(L[j-1]); bitset<32> tmpR(f(R[j-1],keys[17-j-1]));
            R[j] = (tmpL^tmpR).to_string() ;
        }
        cipher += finalPermutation(R[16]+L[16]);
    }
    //cout << cipher << endl;
    return StrToHex(cipher) ;
}


string CDES::initialPermutation(string t)
{
    int p[]={58,50,42,34,26,18,10,2,
             60,52,44,36,28,20,12,4,
             62,54,46,38,30,22,14,6,
             64,56,48,40,32,24,16,8,
             57,49,41,33,25,17, 9,1,
             59,51,43,35,27,19,11,3,
             61,53,45,37,29,21,13,5,
             63,55,47,39,31,23,15,7};
    string change;
    for(int i=0; i< 64 ; i++)
        change += t[p[i]-1];
    return change;
}

string CDES::finalPermutation(string t)
{
    int p[]={ 40, 8,48,16,56,24,64,32,
              39, 7,47,15,55,23,63,31,
              38, 6,46,14,54,22,62,30,
              37, 5,45,13,53,21,61,29,
              36, 4,44,12,52,20,60,28,
              35, 3,43,11,51,19,59,27,
              34, 2,42,10,50,18,58,26,
              33, 1,41, 9,49,17,57,25};
    string change;
    for(int i=0; i< 64 ; i++)
        change += t[p[i]-1];
    return change;
}


string CDES::PermutationP(string t)
{
    int p[]={16, 7,20,21,
             29,12,28,17,
             1,15,23,26,
             5,18,31,10,
             2, 8,24,14,
             32,27, 3, 9,
             19,13,30, 6,
             22,11, 4,25};
    string change;
    for(int i=0; i< 32 ; i++)
        change += t[p[i]-1];
    return change;
}
string CDES::HexToBin(string s)
{
    string binary; string tmp;
    for(int i=0; i< s.size(); i++){
        stringstream ss;
        tmp = s.substr(i,1);
        ss << std::hex << tmp;
        unsigned n;
        ss >> n;
        bitset<4> b(n);
        binary+= b.to_string();
    }
    return binary;
}

string CDES::Convert64to56Bits(string binary)
{
    int changes[56]={56,49,41,33,25,17, 9,
                     1,58,50,42,34,26,18,
                     10, 2,59,51,43,35,27,
                     19,11, 3,60,52,44,36,
                     63,55,47,39,31,23,15,
                     7,62,54,46,38,30,23,
                     14, 6,61,53,45,37,29,
                     21,13, 5,28,20,12, 4};

    string bin;
    for(int i=0; i<56 ; i++)
        bin+= binary[changes[i]-1];

    return bin;
}

string CDES::Convert56to48Bits(string binary)
{
    int changes[48]={14,17,11,24, 1, 5,
                     3,28,15, 6,21,10,
                     23,19,12, 4,26, 8,
                     16, 7,27,20,13, 2,
                     41,52,31,37,47,55,
                     30,40,51,45,33,48,
                     44,49,39,56,34,53,
                     46,42,50,36,29,32};

    string bin;
    for(int i=0; i<48 ; i++)
        bin += binary[changes[i]-1];

    //cout << "binary: "<< binary<< endl;
    //cout << "bin :   "<< bin << endl;
    return bin;
}

string CDES::Convert32to48Bits(string binary)
{
    int changes[48]={32, 1, 2, 3, 4, 5,
                     4, 5, 6, 7, 8, 9,
                     8, 9,10,11,12,13,
                     12,13,14,15,16,17,
                     16,17,18,19,20,21,
                     20,21,22,23,24,25,
                     24,25,26,27,28,29,
                     28,29,30,31,32, 1};

    string bin;
    for(int i=0; i<48 ; i++)
        bin+= binary[changes[i]-1];
    return bin;
}

string CDES::leftShift(string text)
{
    string aux = text.substr(0,1);
    bitset<28> tmp(text);
    tmp<<=1;
    string aux2 = tmp.to_string();
    aux2[27] = aux[0];
    return aux2;
}


string CDES::rightShift(string text)
{
    //int size = text.size();
    string aux = text.substr(28-1,1);
    bitset<28> tmp(text);
    tmp>>=1;
    string aux2 =  tmp.to_string();
    aux2[0] = aux[0];
    return aux2;
}

string CDES::XOR(string k, string r)
{
    //cout << "XOR: "<< r << " " << r.size()<< endl;
    bitset<48> ko(k); bitset<48> ro(r);
    ko ^= ro;
    return ko.to_string();
}

string CDES::StrToHex(string t)
{
    string hex;
    string aux[]={"A","B","C","D","E","F"};

    for(int j=0; j<t.size(); j+=4){
        long tmp = bitset<4>(t.substr(j,j+4)).to_ulong();
        if(tmp>9)
            hex += aux[tmp-10];
        else
            hex += to_string(tmp);
    }
    return hex;
}

long CDES::to_int2(string a)
{
    return bitset<2>(a).to_ulong();
}

long CDES::to_int4(string a)
{
    return bitset<4>(a).to_ulong();
}
string CDES::toBinary(int v)
{
    return bitset<4>(v).to_string();
}

string CDES::fill(string cadena, string relleno, int tam)
{
    //ZZ tam = ZZ(ZZtos(n).size())-1 ;
    while( cadena.size()%tam !=0  )
    {
        cadena += relleno;
    }
    return cadena;
}

#endif //COMPUTER_SECURITY_FINAL_DES_H
