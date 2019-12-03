#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TAM_MAX_DATA 650

int main(int argc, char const *argv[])
{
    int nbd = 0;
    int monto;
    //int num_depositos = atoi(argv[3]);
    char* ip = (char *) argv[1];
    int puerto = atoi(argv[2]);
    //int id = atoi(argv[4]);

    SocketMulticast socketMulticast(puerto);
    PaqueteDatagrama paqueteDatagrama_Recepcion(sizeof(int));
    socketMulticast.unirseGrupo(ip);     

    while ( 1 ) {
        //std::cout<< nbd << std::endl;
        socketMulticast.recibeConfiable(paqueteDatagrama_Recepcion);
        memcpy(&monto,paqueteDatagrama_Recepcion.obtieneDatos(),sizeof(int));
        nbd = monto + nbd;
        //std::cout<< monto << std::endl;
        std::cout<< "NBD: "<<nbd << std::endl;
    }

    socketMulticast.salirseGrupo(ip);

    //std::cout << "Cliente: \n" <<  "IP:" << paqueteDatagrama_Recepcion.obtieneDireccion();
    //std::cout << ", Puerto: " << paqueteDatagrama_Recepcion.obtienePuerto() << "\n";
    //std::cout << "NBD = " << nbd << std::endl;

    return 0;
}
