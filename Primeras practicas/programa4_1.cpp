#include <iostream>
#include "PoligonoIrre.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    vector <PoligonoIrre> v2;
    v2.resize(2);
    double x,y,num;
    int tam=3+rand()%(10-1);

    
    for(int i=0;i<v2.size();i++){
        tam=3+rand()%(10-1);
        v2[i].setTam(tam);
        for(int j=0;j<v2[i].tamVector();j++){
            num=-100+rand()%(101-1);
            x=num;
            num=(-100+rand()%(101-1))*-1;
            y=num;
            v2[i].agregarCoordenada(x,y,j);
        }
        cout<<"-------------------"<<endl;
    }

    for(int i=0;i<v2.size();i++){
        v2[i].imprimeVertices();
    }

    cout<<"Tam:"<<v2[0].getTam()<<endl;
    return 0;
}