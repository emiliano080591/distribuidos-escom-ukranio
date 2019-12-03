#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <istream>
#include <fstream>
#include <ostream>
#include <sys/time.h>
#include <bits/stdc++.h> 

#define TAM_MAX_DATA 650

using namespace std;

int main(int argc, char const *argv[])
{
    char registro[110];
    struct timeval recibido;
    char* ip = (char *) argv[1];
    int puerto = atoi(argv[2]);
    int errorCount=0;
    char numTel[110];
    vector<string> numerosTel;
    //ruta donde se va a guardar el archivo
    char ruta[100] = "/home/emiliano/Downloads/"; 
    //argv[3] nombre del archivo donde se van a guardar los registros
    
    strcat(ruta,argv[3]);
    cout << "Archivo creado en..."<<ruta<<endl;
    ofstream file(ruta);

    SocketDatagrama socket(puerto);
    PaqueteDatagrama paqueteDatagrama_Recepcion(sizeof(registro)); 
    PaqueteDatagrama paqueteacuse(sizeof(registro));
    int cont=0;
    while(cont<10){
        gettimeofday(&recibido, NULL);
        int res=socket.recibeTimeout(paqueteDatagrama_Recepcion,1,5000);
        if(res>0){
            //cout << "Cliente: \n" <<  "IP:" << paqueteDatagrama_Recepcion.obtieneDireccion();
            //cout << ", Puerto: " << paqueteDatagrama_Recepcion.obtienePuerto() << "\n";
            memcpy(&registro,paqueteDatagrama_Recepcion.obtieneDatos(),sizeof(registro));
            memcpy(&numTel,paqueteDatagrama_Recepcion.obtieneDatos(),sizeof(registro));
            string str(strtok(numTel,"_"));
            
            if(binary_search(numerosTel.begin(),numerosTel.end(),str)){
                //cout<<"ya esta registrado"<<endl;
                char response[120];
                strcat(response,registro);
                strcat(response,"_0_0");
                PaqueteDatagrama paqueteacuse((char*)response,sizeof(response),ip,puerto);
                socket.envia(paqueteacuse);
            }else{
                numerosTel.push_back(str);
                sort(numerosTel.begin(),numerosTel.end());
                //cont++;
                //cout<<"No esta registrado"<<endl;
                string str(registro);
                str+="_"+recibido.tv_sec;
                str+="_"+recibido.tv_usec;
                //cout<<str<<endl;
                char response[str.length()+1];
                strcpy(response, str.c_str());
                //cout<<"Char repsonse "<<response<<endl;
                file << registro <<"_"<<recibido.tv_sec<<"_"<<recibido.tv_usec<<endl;
                PaqueteDatagrama paqueteacuse((char*)response,sizeof(response),ip,puerto);
                socket.envia(paqueteacuse);
            } 
            //cout<<"Registro recibido: " << numTel << endl;
        }else{
            cout<<"Error al recibir..."<<endl;
        }
        
    }
    file.close();
    /*
    for(vector<string>::const_iterator i=numerosTel.begin();i!=numerosTel.end();++i){
        cout<<*i<<endl;
    }*/
    return 0;
}

/*compilar con make -f Makefile*/