#include <iostream>
#include "Fecha.h"
using namespace std;

int main(){
    int count=0;
    Fecha a, b, c(21, 9, 1973);
    b.inicializaFecha(17, 6 , 2010);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();
    cout<<c.convierte()<<endl;
    for(int i=1;i<2020;i++){
        b.inicializaFecha(17,6,i);
        if(b.leapyr()){
            count++;
        }    
    }

    /*
    if(b.leapyr()){
        cout<<"Es bisiesto"<<endl;
    }else{
        cout<<"NO es bisiesto"<<endl;
    }*/
    
    cout<<"Numero de años bisiestos entre el año 1 y el 2019: "<<count<<endl;
    return 0;
}