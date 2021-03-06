#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

SocketDatagrama::SocketDatagrama(int puerto){
    s = socket(AF_INET, SOCK_DGRAM, 0);
    std::cout << "Status del socket: " << s << std::endl;
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY inet_addr(argv[1])
    direccionLocal.sin_port = htons(puerto);
    int b = bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
    std::cout << "Status de Bind: " << b << std::endl;
}

SocketDatagrama::~SocketDatagrama(){
    close(s);
}

int SocketDatagrama::envia(PaqueteDatagrama &paqueteDatagrama){
    int client = sizeof(direccionForanea);
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(paqueteDatagrama.obtieneDireccion());
    direccionForanea.sin_port = htons(paqueteDatagrama.obtienePuerto());
    int res=sendto(s, paqueteDatagrama.obtieneDatos(), paqueteDatagrama.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t)client);
    return res;
}

int SocketDatagrama::recibe(PaqueteDatagrama &paqueteDatagrama){
    int client = sizeof(direccionForanea);
    int n = recvfrom(s, paqueteDatagrama.obtieneDatos(), paqueteDatagrama.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t*)&client);
    paqueteDatagrama.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    paqueteDatagrama.inicializaPuerto(ntohs(direccionForanea.sin_port));
    
    return n;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos) {
    int client = sizeof(direccionForanea);
    timeval.tv_sec = segundos;
    timeval.tv_usec = microsegundos;
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeval, sizeof(timeval));
    int n = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, (socklen_t*)&client);
    //std::cout << "Dentro de timeOut n: " << n << std::endl;
    p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    /*
    if ( n < 0 ) {
        if (errno == EWOULDBLOCK) {
            fprintf(stderr, "Tiempo para recepción transcurrido\n"); 
        } else
            fprintf(stderr, "Error en recvfrom\n");
        return -1;
    }*/
    return n;

}

struct sockaddr_in SocketDatagrama::getDirForanea() {
    return this->direccionForanea;
}
