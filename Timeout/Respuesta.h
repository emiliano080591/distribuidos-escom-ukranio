#ifndef RESPUESTA_H_
#define RESPUESTA_H_

#include "SocketDatagrama.h"
#include "Mensaje.h"
#include <netdb.h>
#include <cstdlib>
#include <cstring>

class Respuesta{

	public:
	    Respuesta(int pl);
	    struct mensaje *getRequest(void);
	    void sendReply(char *respuesta, char* ipCliente, int puertoCliente);
	private:
		SocketDatagrama *socketlocal;
};

#endif