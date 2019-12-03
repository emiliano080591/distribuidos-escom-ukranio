#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>
#include "Mensaje.h"
#include "Respuesta.h"

#define TAM 200
char cadena2[TAM];
using namespace std;

int main(int argc, char*argv[]) {
    
    Respuesta respuesta(7200);
    int nbd = 0, total = 0;
    int id_paquete = 0;
    int num_paquetes = 0;

    printf("%s\n", "Servidor conectado...");
    while(true) {
        //printf("%s\n", "\t->Esperando peticion...");
        struct mensaje *msg = respuesta.getRequest();
        string cadenaRecibida = msg->arguments;

        if(cadenaRecibida == "Info"){
            //cout<<"\t\t->Recibido: "<<cadenaRecibida<<endl;
            num_paquetes = msg->operationId;
            respuesta.sendReply((char *)"Entregado paquetes", msg->IP, msg->puerto);
            fflush(stdin);
        }else{
            //cout<<"\t\t->Recibido: "<<cadenaRecibida<<endl;
            if(id_paquete == msg->requestId){
                     //   cout << "\t\t\t->Paquete repetido "<<endl;
            }else{
                id_paquete = msg->requestId;
                switch(msg->operationId) {
                    case 1: //Lectura
                        char buffer[100];
                        sprintf (buffer, "%d", total);

                        respuesta.sendReply((char *)buffer, msg->IP, msg->puerto);
                        fflush(stdin);
                        //cout << "\t\t->Respuesta enviada..." << endl;
                    break;
                    default: //Escritura
                        int num[100];
                        memcpy(&num,msg->arguments,sizeof(num));
                        //cout<<nbd<<endl;
                        total += num[0];
                        //cout<<"NUMMMMMMM :  "<<num[0]<<endl;
                        buffer[100];
                        sprintf (buffer, "%d", total);

                        respuesta.sendReply((char *)buffer, msg->IP, msg->puerto);
                        fflush(stdin);
                        //cout << "\t\t->Respuesta enviada..." << buffer <<endl;
                    break;
                }
                if(num_paquetes == msg->operationId){
                    num_paquetes = 0;
                    id_paquete = 0;
                    fflush(stdin);
                }
            }
        }
    }

}

