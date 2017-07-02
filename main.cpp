//
// Created by jhoelccari on 11/06/17.
//

#include <NTL/ZZ.h>
#include <iostream>
#include <vector>
//#include "ssl.cpp"
#include "libreria.h"
//#include "3DES.h"
using namespace std;
using namespace NTL;

int main(){
    /*
    TDES* des = new TDES();
    des->KTDES("133457799BBCDFF1","CNDFDJFH13SK34F4","KASDJHFU1343183F");
    string cipher = des->cipher("123454ABC123454ABC123454ABC123454ABC123454ABC123454ABC");
    string decipher = des->decipher(cipher);
    cout << decipher << endl;
    */
    ZZ MK = ZZ(565);
    int dMK, a = 0;
    dMK = conv<int>(MK);
    vector<string> keys;
    char buffer[2];
    string str="";
    string clave;
    for (int j = 0; j < 3; j++) {
        clave = "";
        int w = 0;
        do {
            //cout <<"..."<<endl;
            a += dMK;// % 16;
            a += rand();
            a = a %16;
            //cout << a << endl;
            str = toHex(a);
            clave += str;
            //dec_to_hex(buffer, a);
            //clave += buffer[1];
            //cout << clave << endl;
            w++;
        } while (w < 16);
        keys.push_back(clave);
    }
    for (int i = 0; i < keys.size(); ++i) {
        cout << keys[i] << endl;
    }


    return 0;
}

/*
    set(SOURCE_FILES
        Alice.h
        BOBServer.h
        PruebaBob.cpp
        libreria.h
        cesar.h
        diffieHellman.h
        RSA.h
        gamal.h
        3DES.h
        DES.h
        tools.h)
*/