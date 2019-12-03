#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
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

    int res;
    char* ip = (char*) argv[1];
    int puerto = atoi(argv[2]),count=1;
    char response[200];
    //crea la cadena para ejecutar el programa que genera los registros 'partidos.cpp'
    //y su ejecutable './partidos numeroDeRegistros'
    string numReg="./partidos "+string(argv[3]);
    char ejecutar[numReg.length()+1];
    strcpy(ejecutar,numReg.c_str());
    //ejecuta el programa partidos pasando un array de char 
    system(ejecutar);  
    
    char cadena[110];
    //abre el archivo donde estan los registros
    ifstream fe("/home/emiliano/Documents/ukranio/programas/votacion2/registros.txt");
    SocketDatagrama socket (puerto);
    int comparar=atoi(argv[3]);
    while(!fe.eof()) {
      fe >> cadena;
      PaqueteDatagrama paqueteDatagrama_Envio((char*)cadena,sizeof(cadena),ip,puerto);
      res=socket.envia(paqueteDatagrama_Envio);
      //cout<<"Se envio el paquete ["<<count<<"]: "<<cadena<<endl;
      while(1){
        PaqueteDatagrama paqueteRecibe(sizeof(cadena));
        //res=socket.envia(paqueteDatagrama_Envio);
        //cout<<"No se envio el paquete ["<<count<<"]:"<<cadena<<endl;
        socket.recibe(paqueteRecibe);
        memcpy(&response,paqueteRecibe.obtieneDatos(),sizeof(response));
        cout<<"Se recibio..."<<response<<endl; 
      }
    }//fin de while que lee el archivo
    fe.close();//cierra el archivo de los registros

}

/*compilar con make -f Makefile*/