#include <iostream>
#include "Rectangulo.h"

using namespace std;

int main(){

    //Rectangulo rectangulo1(2,3,5,1);
    Rectangulo rectangulo1(Coordenada(2,3,3.6,0.98),Coordenada(5,1,5.1,0.2));

    cout<<"Calculando el area de un rectangulo dadas sus coordenadas en un plano cartesiano:\n";
    rectangulo1.imprimeEsq();

    cout<<"El area del rectangulo es= "<<rectangulo1.obtieneArea()<<endl;
    return 0;
}