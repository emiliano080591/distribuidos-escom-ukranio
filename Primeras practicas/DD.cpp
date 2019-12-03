#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]){
    string cadenaGigante, cadenaBaby;
    int destino;
    string linea;
    char c;
    char buffer[BUFSIZ];
    int num, count = 0, count2 = 0, tam = 17563*100;

    if(argc != 2){
        cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
        exit(0);
    }
    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
    {
        perror(argv[1]);
        exit(-1);
    }
 
    for(int i=0; i<10000; i++){
        for(int i=0;i<3;i++){
            num = 65 + rand() % (91 - 65);
            c=(char)num;
            cadenaBaby+=c;
        }
        cadenaBaby+=" ";
        strcpy(buffer, cadenaBaby.c_str( ));
        write(destino, buffer, 1024);
        
    }
    cout<<cadenaGigante<<endl;
    return 0;
}