//
// Created by jhoelccari on 11/06/17.
//

//#include <NTL/ZZ.h>
#include "ssl.cpp"
#include <iostream>
#include "3DES.h"
using namespace std;
//using namespace NTL;

int main(){
    TDES* des = new TDES();
    des->KTDES("133457799BBCDFF1","CNDFDJFH13SK34F4","KASDJHFU1343183F");
    string cipher = des->cipher("123454ABC123454ABC123454ABC123454ABC123454ABC123454ABC");
    string decipher = des->decipher(cipher);
    cout << decipher << endl;

    return 0;
}
