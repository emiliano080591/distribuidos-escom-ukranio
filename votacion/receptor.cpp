#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <istream>
#include <fstream>
#include <ostream>

#define TAM_MAX_DATA 650

using namespace std;
int main(int argc, char const *argv[])
{
    int nbd = 0;
    char monto[11];
    //int num_depositos = atoi(argv[3]);
    char* ip = (char *) argv[1];
    
    int puerto = atoi(argv[2]);
    //int id = atoi(argv[4]);

    char ruta[100] = "/home/oscar/Documentos/Sistemas_Distribuidos/SegundaOportunidad/Practica_18/";
    
    strcat(ruta,argv[3]);
    cout << ruta;
    ofstream file(ruta);



    SocketDatagrama socket(puerto);
    PaqueteDatagrama paqueteDatagrama_Recepcion(sizeof(monto));

    while(1){
        socket.recibe(paqueteDatagrama_Recepcion);
        memcpy(&monto,paqueteDatagrama_Recepcion.obtieneDatos(),sizeof(monto));
        file << monto << endl;
        std::cout<<"Registro recibido: " << monto << std::endl;
    }
    file.close();


    std::cout << "Cliente: \n" <<  "IP:" << paqueteDatagrama_Recepcion.obtieneDireccion();
    std::cout << ", Puerto: " << paqueteDatagrama_Recepcion.obtienePuerto() << "\n";

    return 0;
}
