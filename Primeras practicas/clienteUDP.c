#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h> 
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>

int puerto=7200;
char *ip;
int main(void){
    struct sockaddr_in msg_to_server_addr, client_addr;
    int s, num[16375], res,i=0;
    
    s = socket(AF_INET, SOCK_DGRAM, 0);
    /* rellena la dirección del servidor */
    bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
    msg_to_server_addr.sin_family = AF_INET;
    msg_to_server_addr.sin_addr.s_addr = inet_addr("10.100.69.217");
    msg_to_server_addr.sin_port = htons(puerto);
    
    /* rellena la direcciòn del cliente*/
    bzero((char *)&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    
    /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
    client_addr.sin_port = htons(6666);
    bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
    for(i=0;i<16375;i++){
        num[i]=5;
    }
    int longitud = sizeof(num) / sizeof(num[0]);
    printf("Longitud: %d\n",longitud);
    sendto(s, (char *)num, 16375 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
    
    /* se bloquea esperando respuesta */
    recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
    printf("Respuesta recibida por el puerto: %d\n",ntohs(msg_to_server_addr.sin_port));
    ip=inet_ntoa(msg_to_server_addr.sin_addr);
    printf("La dirección del servidor es: %s\n",ip);
    printf("10 + 5 = %d\n", res);
    close(s);
}