#include "SocketDatagrama.h"
#include "mensaje.h"

#ifndef RESPUESTA_H_
#define RESPUESTA_H_

class Respuesta {
private:
    SocketDatagrama *socketlocal;
    struct mensaje _mensaje;
public:
    Respuesta(int pl);
    struct mensaje* getRequest(void);
    void sendReply(char* respuesta);
    SocketDatagrama* getSocket();
};

#endif
