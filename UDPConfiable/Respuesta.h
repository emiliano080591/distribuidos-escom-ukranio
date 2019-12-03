#ifndef __Respuesta__
#define __Respuesta__

#include "SocketDatagrama.h"
#include "Mensaje.h"

using namespace std;

class Respuesta {

public:
    Respuesta(int pl);
    struct mensaje *getRequest(void);
    void sendReply(char *respuesta, char *ipCliente, int puertoCliente);

private:
    SocketDatagrama *socketlocal;
    struct mensaje *palabras;
};

#endif
