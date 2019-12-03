#include "Coordenada.h"
#include <iostream>
#include <math.h>

using namespace std;

Coordenada::Coordenada(double xx,double yy): x(xx),y(yy)
{
    magnitud=sqrt(pow(x,2)+(pow(y,2)));
}

double Coordenada::obtenerX(){
    //x=r*cos(t);
    return x;
}

double Coordenada::obtenerY(){
    //y=r*sin(t);
    return y;
}

double Coordenada::getManitud(){
    return magnitud;
}
