//
// Created by jhoelccari on 26/06/17.
//

#ifndef COMPUTER_SECURITY_FINAL_TOOLS_H
#define COMPUTER_SECURITY_FINAL_TOOLS_H

#include <vector>
#include <iostream>
using namespace std;

vector<string> matchingAlgoritmos(vector<string> server, vector<string> client ){
    vector<string> result;
    for( int i=0; i< server.size(); i++){
        for (int j = 0; j < client.size(); j++) {
            if( server[i]==client[j])
                result.push_back(server[i]);
        }
    }
    return result;
}


#endif //COMPUTER_SECURITY_FINAL_TOOLS_H
