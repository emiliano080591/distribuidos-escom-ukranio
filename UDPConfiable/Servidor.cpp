#include <cstdlib>
#include <string>
#include "Respuesta.h"

using namespace std;

int main(int argc, char const *argv[]) {

	Respuesta respuesta(atoi(argv[1]));

	while(1) {
		struct mensaje msj;
    	struct mensaje m1;
		int nums[2];
		cout << "\nEsperando conexion : " << endl;
		memcpy(&msj, respuesta.getRequest(), sizeof(struct mensaje));
    	cout << "REVISA ESTOOOOO: " << endl;
    	cout<<msj.IP<<" "<<msj.puerto<<" "<<msj.operationId<<" "<<msj.arguments<<endl;
		memcpy(&nums,msj.arguments,sizeof(nums));
		
		cout << "id: " << msj.operationId << endl;
		cout<< "IP: " <<msj.IP<<endl;
		
    	switch(msj.operationId) {
			case 1:
				cout << "Id encontrado :  1" << endl;
				cout << "La suma es : " << nums[0]+nums[1] << endl;
				int suma;
				suma=nums[0]+nums[1];
		        memcpy(m1.arguments,(char *)&suma , sizeof(suma));

        		m1.messageType = 1;
        		memcpy(m1.IP, msj.IP, 16);//------------------
        		m1.puerto = msj.puerto;
        		m1.requestId = msj.requestId;
				respuesta.sendReply((char*) m1.arguments,m1.IP, msj.puerto);
				cout << "Fin del servicio" << endl;
        break;
			default:
				cout << "Error en el numero de operación" << endl;
				cout << "numero: " << msj.operationId << endl;
				exit(-1);
		}
	}//fin de while

	return 0;
}