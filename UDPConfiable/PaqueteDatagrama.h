#define PAQUETE_DATAGRAMA_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <iostream>

#include <cstring>

using namespace std;

class PaqueteDatagrama {
    
public:
    PaqueteDatagrama(char *, unsigned int, char *, int );
    PaqueteDatagrama(unsigned int );
    ~PaqueteDatagrama();
    char *obtieneDireccion();
    unsigned int obtieneLongitud();
    int obtienePuerto();
    char *obtieneDatos();
    void inicializaPuerto(int);
    void inicializaIp(char *);
    void inicializaDatos(char *);
    
private:
    char *datos;
    char ip[16];
    unsigned int longitud;
    int puerto;
};