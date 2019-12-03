#include "Solicitud.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

#define TAM_MAX_DATA 65000

Solicitud::Solicitud() {
    socketLocal = new SocketDatagrama(0);
}

char* Solicitud::doOperation(char * ip,int puerto, int operationid, char* arguments, unsigned int id) {
    mensaje mensajeEnvio;
    mensaje m;
    int veces = 7,n,resp;

    memcpy(mensajeEnvio.arguments,arguments,TAM_MAX_DATA);
    mensajeEnvio.messageType = 0;
    mensajeEnvio.operationId = operationid;
    mensajeEnvio.requestId = id;

    std::cout << mensajeEnvio.arguments << std::endl;

    PaqueteDatagrama paqueteDatagrama_Envio((char*)&mensajeEnvio,sizeof(mensaje), ip, puerto);
    std::cout << "Esperando respuesta del servidor..." << std::endl;
   
    //Se crea el paquete donde se recibira la respueta del servidor
    PaqueteDatagrama paqueteDatagrama_Recepcion(sizeof(mensaje));
    //Se recibe el paquete del servidor
    //socketLocal->recibe(paqueteDatagrama_Recepcion);

    do {
        socketLocal -> envia(paqueteDatagrama_Envio);
        n = socketLocal->recibeTimeout(paqueteDatagrama_Recepcion,2,500000);
        if (n != -1)
            break;
        veces--;
        std::cout << "Veces: " << veces << std::endl;
    }while((veces > 0));

    if (n == -1) {

         std::cout << "Se ha agotado el tiempo de respuesta" << std::endl;
         exit(0);

    } else {

        std::cout << "Cliente: \n" <<  "IP:" << paqueteDatagrama_Recepcion.obtieneDireccion();
        std::cout << ", Puerto: " << paqueteDatagrama_Recepcion.obtienePuerto() << "\n" << std::endl;

        memcpy(&_mensaje,paqueteDatagrama_Recepcion.obtieneDatos(),sizeof(mensaje));

         memcpy(&resp,&_mensaje.arguments,sizeof(int));
        //printf("Result = %d\n", resp[0]);
        std::cout << "La respuesta es: " << resp << std::endl; 

    }

    return _mensaje.arguments;
    
}

SocketDatagrama* Solicitud::getSocket() {
    return this->socketLocal;
}
