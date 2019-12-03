#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <sstream>     
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
 
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
 
  return internal;
}

int main(){
    int num;
    string cadenaChica("");
    string cadenaGrande("");
    string s;
    srand(time(NULL));

    for(int j=0;j<100;j++){
        for(int i=0;i<3;i++){
            num = 65 + rand() % (91 - 65);
            char caracter=(char)num;
            cadenaChica+=caracter;
        }
        cadenaChica+=" ";
        cadenaGrande+=cadenaChica;
        cadenaChica="";
    }
    int count=0;
    vector<string> sep = split(cadenaGrande,' ');
    for(int i = 0; i < sep.size(); ++i){
        if(sep[i].compare("IPN")!=0){
            count++;
        }
    }

    cout<<"Se encontro IPN "<<count<<" veces."<<endl;
    return 0;
}