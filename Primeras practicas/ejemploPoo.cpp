#include<iostream>
using namespace std;

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int=3,int=4,int=2019);
        void inicializarFecha(int,int,int);
        void muestraFecha();
};

Fecha::Fecha(int dd,int mm,int aaaa){
    mes=mm;
    dia=dd;
    anio=aaaa;
}