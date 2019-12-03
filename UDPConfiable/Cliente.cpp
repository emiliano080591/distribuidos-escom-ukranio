#include "Solicitud.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char*argv[]) {
    int numeros[2];
    numeros[0]=15;
    numeros[1]=12;
    char *ip;
    int puerto;
    int operacion = 1;
   
    ip =argv[1];
    puerto = atoi(argv[2]);
    Solicitud cliente;

    cliente.doOperation(ip, puerto, operacion, (char *)numeros);

    return 0;
}