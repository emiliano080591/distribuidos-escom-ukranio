#include "SocketDatagrama.h"
#include "mensaje.h"

#ifndef SOLICITUD_H_
#define SOLICITUD_H_

class Solicitud {
private:
    SocketDatagrama *socketLocal;
    struct mensaje _mensaje;    
public:
    Solicitud();
    char*  doOperation(char * ip,int puerto, int operationid, char* arguments, unsigned int id);
    SocketDatagrama* getSocket();
};

#endif
