#include <iostream>
#include "PoligonoIrre.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

int main(){
    vector <PoligonoIrre> v2;
    v2.resize(2);
    double x,y,num;
    int tam=3+rand()%(10-1);
    srand((unsigned) time(NULL));
   
    for(int i=0;i<v2.size();i++){
        tam=3+rand()%(10-1);
        v2[i].setTam(tam);
        for(int j=0;j<v2[i].tamVector();j++){
            num=(double)rand()/(RAND_MAX+1)*(96-12)+12;
            x=num;
            num=-1*(double)rand()/(RAND_MAX+1)*(96-12)+12;
            y=num;
            v2[i].agregarCoordenada(x,y,j);
        }
    }

    cout<<"Tam:"<<v2[0].getTam()<<endl;
    for(int i=0;i<v2.size();i++){
        v2[i].imprimeVertices();
        cout<<"-----------------------------"<<endl;
        cout<<"Magnitud de vertices con sort"<<endl;
        v2[i].obtenerA();
        cout<<"\n-----------------------------"<<endl<<endl;
    }


    return 0;
}