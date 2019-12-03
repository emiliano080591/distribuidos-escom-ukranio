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
#include <fstream>
#include <istream>
#include <ostream>

#define TAM_MAX_DATA 650

using namespace std;
int main(int argc, char const *argv[]){
    //srand (time(NULL));

    char* ip = (char*) argv[1];
    int puerto = atoi(argv[2]);
    //int t = atoi(argv[3]);
    //int numd = atoi(argv[3]);

    char cadena[11];
    ifstream fe("/home/oscar/Descargas/registros.txt");
    while(!fe.eof()) {
      fe >> cadena;
      cout << cadena << endl;
    }
    fe.close();

    //SocketMulticast socketMulticast(puerto);
    SocketDatagrama socket (puerto);
    PaqueteDatagrama paqueteDatagrama_Envio((char*)cadena,sizeof(cadena),ip,puerto);
    socket.envia(paqueteDatagrama_Envio);
    std::cout << "Enviado " << cadena << std::endl;
}
