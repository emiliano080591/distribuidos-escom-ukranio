#include "Coordenada.h"
#include <vector>
#ifndef POLIGONOIRRE_H_
#define POLIGONOIRRE_H_

using namespace std;

class PoligonoIrre
{
private:
    vector <Coordenada> v;
    Coordenada nuevaCoordenada;
public:
    static int tam;
    PoligonoIrre();
    int tamVector();
    void setTam(int);
    void imprimeVertices();
    void agregarCoordenada(double, double,int);
    void obtenerA();
    static int getTam(); 
};

#endif