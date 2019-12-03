#include "SocketMulticast.h" 
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

SocketMulticast::SocketMulticast(int puerto) {
    s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    int reuse = 1;
    if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) == -1) {
        printf("Error al llamar a la función setsockopt\n");
        exit(0);
    }
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY inet_addr(argv[1])
    direccionLocal.sin_port = htons(puerto);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketMulticast::~SocketMulticast() {
    close(s);
}

void SocketMulticast::unirseGrupo(char* ip) {
    multicast.imr_multiaddr.s_addr = inet_addr(ip);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
}

void SocketMulticast::salirseGrupo(char *ip) {
    if ( multicast.imr_multiaddr.s_addr == inet_addr(ip) ) {
        setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *) &multicast, sizeof(multicast));       
    }
}

int SocketMulticast::envia(PaqueteDatagrama &paqueteDatagrama, unsigned char ttl) {
    
    int n = setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &ttl, sizeof(ttl));

    if ( n < 0 ) {
         printf("Ha ocurrido un error al enviar el paquete \n");
    } else {
        int client = sizeof(direccionForanea);
        bzero((char *)&direccionForanea, sizeof(direccionForanea));
        direccionForanea.sin_family = AF_INET;
        direccionForanea.sin_addr.s_addr = inet_addr(paqueteDatagrama.obtieneDireccion());
        direccionForanea.sin_port = htons(paqueteDatagrama.obtienePuerto());
        sendto(s, paqueteDatagrama.obtieneDatos(), paqueteDatagrama.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t)client);
    }
    
}

int SocketMulticast::enviaConfiable(PaqueteDatagrama & paqueteDatagrama, unsigned char ttl, int num_receptores) {
    int n = setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &ttl, sizeof(ttl));
    int contador = 0, id,nn;

    if ( n < 0 ) {
         printf("Ha ocurrido un error al enviar el paquete \n");
    } else {
        int client = sizeof(direccionForanea);
        bzero((char *)&direccionForanea, sizeof(direccionForanea));
        direccionForanea.sin_family = AF_INET;
        direccionForanea.sin_addr.s_addr = inet_addr(paqueteDatagrama.obtieneDireccion());
        direccionForanea.sin_port = htons(paqueteDatagrama.obtienePuerto());
        sendto(s, paqueteDatagrama.obtieneDatos(), paqueteDatagrama.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t)client);
    }

    SocketDatagrama socketUnicast(7200);

    for(int i = 0; i < num_receptores; i++ ){
        
        PaqueteDatagrama confirmacion(sizeof(int));
        
        do{
            nn = socketUnicast.recibeTimeout(confirmacion,2,500000);
            //std::cout << "AAAAAAAAAAA" << std::endl;
        }while(nn==-1);
        
        memcpy(&id,confirmacion.obtieneDatos(),sizeof(int));
        //std::cout << "El id: " << id << std::endl;
        //std::cout << "N: "<< nn << std::endl;
        if( nn != -1 ) {
            contador++;
            //std::cout << "Contador: " << contador << std::endl; 
        }
        else 
            break;
    }

    socketUnicast.~SocketDatagrama();

    if (num_receptores == contador) 
        return 1;
    else 
        std::cout << "FALTARON RESPUESTAS" << std::endl; return -1;
    

}

int SocketMulticast::recibe(PaqueteDatagrama &paqueteDatagrama) {
    int client = sizeof(direccionForanea);
    int n = recvfrom(s, paqueteDatagrama.obtieneDatos(), paqueteDatagrama.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t*)&client);
    paqueteDatagrama.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    paqueteDatagrama.inicializaPuerto(ntohs(direccionForanea.sin_port));
    
    return n;
}

int SocketMulticast::recibeConfiable(PaqueteDatagrama &paqueteDatagrama) {
    int aux;
    int client = sizeof(direccionForanea);
    int n = recvfrom(s, paqueteDatagrama.obtieneDatos(), paqueteDatagrama.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t*)&client);
    
    paqueteDatagrama.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    paqueteDatagrama.inicializaPuerto(ntohs(direccionForanea.sin_port));
    std::cout << paqueteDatagrama.obtieneDireccion() << std::endl;
    
    SocketDatagrama socketUnicast(6666);
    //int aux = 123;
    //int* resp = &(id);    
    PaqueteDatagrama confirmacion(paqueteDatagrama.obtieneDatos(), sizeof(int),paqueteDatagrama.obtieneDireccion(),7200);
    socketUnicast.envia(confirmacion);
    socketUnicast.~SocketDatagrama();

    memcpy(&aux,paqueteDatagrama.obtieneDatos(),sizeof(int));

    return aux;
}

