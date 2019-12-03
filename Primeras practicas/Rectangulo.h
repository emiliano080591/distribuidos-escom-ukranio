#include "Coordenada.h"
#ifndef RECTANGULO_H_
#define RECTANGULO_H_

class Rectangulo
{
private:
    Coordenada superiorIzq;
    Coordenada inferiorDer;
public:
    Rectangulo();
    Rectangulo(double xSupIzq,double ySupIzq,double xInfDer,double yInfDer);
    Rectangulo(Coordenada coord,Coordenada coord2);
    void imprimeEsq();
    double obtieneArea();
    Coordenada obtieneSupIzq();
    Coordenada obtieneInfDer();
};

#endif