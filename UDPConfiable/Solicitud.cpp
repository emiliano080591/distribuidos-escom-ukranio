#include "SocketDatagrama.h"
#include "Solicitud.h"
#include "Mensaje.h"
#include <iostream>

Solicitud::Solicitud() {
	socketlocal = new SocketDatagrama(0);
}

char * Solicitud::doOperation(char* IP, int puerto, int operationId, char* arguments) {
	struct mensaje msj;
	msj.messageType = 0;
	msj.requestId = id;
	id++;
	memcpy(msj.IP, IP, 16);
	msj.puerto = puerto;
	msj.operationId = operationId;

	cout << "Id operacion: " << msj.operationId << endl;

	cout << "ip: " << msj.IP << endl;
	memcpy(msj.arguments, arguments, 100);
	cout << "puerto: " << msj.puerto << endl;
	cout << "argumentos: " << msj.arguments << endl;

	//SocketDatagrama socket(puerto);
	PaqueteDatagrama paq((char*) &msj, sizeof(msj), IP, puerto);
	int cont=0;
	while (cont<7)
	{
		cont++;
		socketlocal->envia(paq);
		PaqueteDatagrama paq1(sizeof(msj));
		socketlocal->recibe(paq1);
		cout<<"Intento..."<<cont<<endl;


		char* resultado;
		resultado = paq1.obtieneDatos();
		int r;
		memcpy(&r,resultado,sizeof(resultado));
		cout << "El resultado de la suma del servidor: " << r << endl;
		return resultado;
	}
		
}