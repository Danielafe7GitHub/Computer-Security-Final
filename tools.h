//
// Created by jhoelccari on 26/06/17.
//

#ifndef COMPUTER_SECURITY_FINAL_TOOLS_H
#define COMPUTER_SECURITY_FINAL_TOOLS_H

#include <vector>
#include <string>

vector<string> recopilar(ifstream * archivo)
{
    string auxiliar;
    vector<string> retorno;
    while (getline(archivo,auxiliar))
    {
        retorno.push_back(auxiliar);
    }
    archivo.close();
    return retorno;
}


#endif //COMPUTER_SECURITY_FINAL_TOOLS_H
