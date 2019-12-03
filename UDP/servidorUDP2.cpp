#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]){
  //int PORT = atoi(argv[1]);
  SocketDatagrama socket = SocketDatagrama(7001);
	int parametros[2];

	while(1){
		PaqueteDatagrama datagrama = PaqueteDatagrama(2 * sizeof(int));
		socket.recibe(&datagrama);

		memcpy(parametros, datagrama.obtieneDatos(), 2 * sizeof(int));

        int num1 = parametros[0];
        int num2 = parametros[1];
        cout<<"Numero 1 recibido: "<<num1<<" Numero 2 recibido:"<<num2<<endl;
        int res=num1+num2;
        cout << " Dirección " << datagrama.obtieneDireccion() <<" "<< "Puerto: " << datagrama.obtienePuerto() << endl;
        PaqueteDatagrama databack =  PaqueteDatagrama((char*) &res, sizeof(bool), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
	    socket.envia(&databack);
    }
    return 0;
}