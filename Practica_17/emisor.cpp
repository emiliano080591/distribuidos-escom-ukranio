#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define TAM_MAX_DATA 650

int main(int argc, char const *argv[]){
    //srand (time(NULL));

    char* ip = (char*) argv[1];
    int puerto = atoi(argv[2]);
    int t = atoi(argv[3]);
    int numd = atoi(argv[4]);
    int numr;
    std::cout<<"Ingresa el numero de receptores"<<std::endl;
    std::cin>>numr;
    unsigned char ttl = (unsigned char) t;

    int nbd = 0;
    int resp,aux;
    int* num;
    int veces = 7,n;

    SocketMulticast socketMulticast(puerto);

    for(int i = 0; i < numd; i++ ){
        aux = rand() %  9 + 1;
        std::cout << aux << std::endl;
        num = &(aux);
        PaqueteDatagrama paqueteDatagrama_Envio((char*)num,sizeof(int),ip,puerto);
        int verificacion = socketMulticast.enviaConfiable(paqueteDatagrama_Envio,ttl,numr);
        std::cout << "Deposito " << i << std::endl;
        if ( verificacion == -1 ) {
            std::cout << "ERROR" << std::endl;
            break;
        }
    return 0;
    }
}
