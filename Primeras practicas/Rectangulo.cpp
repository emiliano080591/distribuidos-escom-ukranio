#include "Rectangulo.h"
#include <iostream>

using namespace std;

Rectangulo::Rectangulo():superiorIzq(0,0),inferiorDer(0,0)
{}

Rectangulo::Rectangulo(double xSupIzq,double ySupIzq,double xInfDer,double yInfDer)
:superiorIzq(xSupIzq,ySupIzq),inferiorDer(xInfDer,xInfDer)
{}

Rectangulo::Rectangulo(Coordenada coord,Coordenada coord2){
    superiorIzq=coord;
    inferiorDer=coord2;
}

void Rectangulo::imprimeEsq(){
    cout<<"Para la esquina superior izquierda.\n";
    cout<<"x= "<<superiorIzq.obtenerX()<<" y= "<<superiorIzq.obtenerY()<<endl;
    cout<<"Para la esquina inferior derecha.\n";
    cout<<"x= "<<inferiorDer.obtenerX()<<" y= "<<inferiorDer.obtenerY()<<endl;
}

double Rectangulo::obtieneArea(){
    double area;
    double alto=obtieneSupIzq().obtenerY()-obtieneInfDer().obtenerY();
    double ancho=obtieneInfDer().obtenerX()-obtieneSupIzq().obtenerX();
    area=alto*ancho;
    if(area<0){
        area=area*-1;
    }
    return alto*ancho;
}

Coordenada Rectangulo::obtieneSupIzq(){
    return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(){
    return inferiorDer;
}
