//
// Created by jhoelccari on 11/06/17.
//

#ifndef COMPUTER_SECURITY_FINAL_3DES_H
#define COMPUTER_SECURITY_FINAL_3DES_H

#include "DES.h"
#include <iostream>
using namespace std;

class TDES{
public:
    CDES* des1;
    CDES* des2;
    CDES* des3;

    TDES(string key1, string key2,string key3){
        des1 = new CDES(key1);
        des2 = new CDES(key2);
        des3 = new CDES(key3);
    }

    string cipher(string plaintext);
    string decipher(string ciphertext);
};

string TDES::cipher(string plaintext) {
    string c1 = des1->cipher(plaintext);
    string c2 = des2->cipher(c1);
    string c3 = des3->cipher(c2);
    return c3;
}

string TDES::decipher(string ciphertext) {
    string d1 = des3->decipher(ciphertext);
    string d2 = des2->decipher(d1);
    string d3 = des1->decipher(d2);
    return d3;
}

#endif //COMPUTER_SECURITY_FINAL_3DES_H
