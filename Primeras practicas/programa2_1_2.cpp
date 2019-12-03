#include <iostream>
#include "Fecha.h"
using namespace std;

void masVieja(Fecha fecha1,Fecha fecha2);

int main(){
    Fecha a, b;
        
    for(int i=0;i<100000000;i++){
        masVieja(a,b);
    }
    
    return 0;
}

void masVieja(Fecha fecha1,Fecha fecha2){
    fecha1.inicializaFecha(17, 6 , 2010);
    fecha2.inicializaFecha(18,4,1999);
    if(fecha1.anio>fecha2.anio){
        //cout<<"Fecha 2 es mas vieja que fecha 1"<<endl;
    }else if(fecha1.anio==fecha2.anio){
        //cout<<"Fecha 1 y Fecha 2 son del mismo año"<<endl;
    }else{
        //cout<<"Fecha 1 es mas vieja que fecha 2"<<endl;
    }
}

