#include <iostream>
#include <stdlib.h>
#include "Solicitud.h"

Solicitud::Solicitud(){
	socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments,  int ident){
    //Preparamos envio
	struct mensaje *msj = (struct mensaje *) malloc(sizeof(mensaje));
	msj->messageType = 0;
    msj->requestId = ident;
    memcpy(msj->IP, IP, strlen(IP));
    msj->puerto = puerto;
    msj->operationId = operationId;
    memcpy(msj->arguments, arguments, sizeof(arguments));

    //Enviamos contenido
    PaqueteDatagrama paquete(sizeof(mensaje));
    paquete.inicializaIp(IP);
    paquete.inicializaPuerto(puerto);
    paquete.inicializaDatos((char *)msj);

    PaqueteDatagrama respuesta(sizeof(struct mensaje));
    int n;
	int intento = 0;
	while(intento < 7) {
		//cout << "Paquete enviado..." << endl;
        socketlocal->envia(paquete);
		//cout<<"\t->Esperando respuesta..."<<endl;
		n = socketlocal->recibeTimeout(respuesta, 2, 500000);		
		if(n > 0){
			break;
		}
		else{
			if (errno == EWOULDBLOCK)
				fprintf(stderr, "\t->Tiempo para recepción transcurrido sin respuesta\n");
			else
				fprintf(stderr, "Error en recvfrom\n");
			intento++;
		}
	}
	if (intento == 7){
		cout<<"\t\t->El servidor no contesto."<<endl;
	}



    struct mensaje *msj_respuesta = (struct mensaje *) malloc(sizeof(mensaje));
    msj_respuesta = (struct mensaje *) respuesta.obtieneDatos();
    
    return msj_respuesta->arguments;
}







