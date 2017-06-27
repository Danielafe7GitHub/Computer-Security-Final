//
// Created by jhoelccari on 26/06/17.
//

#ifndef COMPUTER_SECURITY_FINAL_TOOLS_H
#define COMPUTER_SECURITY_FINAL_TOOLS_H

#include <vector>
#include <iostream>
#include "cesar.h"
#include <NTL/ZZ.h>

using namespace std;

vector<string> matchingAlgoritmos(vector<string> server, vector<string> client ){
    cout << " EN matching algoritmos " << endl;
    vector<string> result;
    for( int i=0; i< server.size(); i++){
        for (int j = 0; j < client.size(); j++) {
            if( server[i]==client[j]) {
                cout << server[i] << endl;
                result.push_back(server[i]);
            }
        }
    }
    return result;
}
vector<string> recopilar(Cesar cesar)
{
    string auxiliar;
    ifstream archivo;
    archivo.open("documento.txt");
    vector<string> retorno;
    while (getline(archivo,auxiliar))
    {
        cout<<"." <<cesar.decipher(auxiliar)<<endl;
        retorno.push_back(cesar.decipher(auxiliar));
    }
    archivo.close();
    return retorno;
}

vector<int> serie(vector<string> algoritmos)
{
    vector <int> res;
    for (int i=0;i<algoritmos.size();i++)
    {
        res.push_back((RandomBits_ZZ(5)%3)+1);
    }
    return res;
}


#endif //COMPUTER_SECURITY_FINAL_TOOLS_H
