#include "Respuesta.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>

#define TAM_MAX_DATA 65000

Respuesta::Respuesta(int puerto) {
    socketlocal = new SocketDatagrama(puerto);
}

struct mensaje* Respuesta::getRequest(void ) {
    //mensaje mensaje_Respuesta;
    PaqueteDatagrama paqueteDatagrama_Recepcion(sizeof(mensaje));
    socketlocal ->  recibe(paqueteDatagrama_Recepcion);

    memcpy(&_mensaje,paqueteDatagrama_Recepcion.obtieneDatos(),sizeof(mensaje));

    return &_mensaje;
}

void Respuesta::sendReply(char* respuesta) {
    mensaje mensaje_Respuesta;

    //strcpy(mensaje_Respuesta.arguments,Respuesta);
    memcpy(mensaje_Respuesta.arguments,respuesta,TAM_MAX_DATA);
    mensaje_Respuesta.messageType = 1;
    mensaje_Respuesta.operationId = 321;
    mensaje_Respuesta.messageType = 0;

    PaqueteDatagrama paqueteDatagrama_Envio((char*)&mensaje_Respuesta,sizeof(mensaje),inet_ntoa(socketlocal -> getDirForanea().sin_addr),ntohs(socketlocal -> getDirForanea().sin_port));
    socketlocal->envia(paqueteDatagrama_Envio);
}

SocketDatagrama* Respuesta::getSocket() {
    return this->socketlocal;
}
