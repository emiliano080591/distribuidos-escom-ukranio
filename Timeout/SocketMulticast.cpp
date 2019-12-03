#include "SocketMulticast.h"
#include <stdio.h>      /* for fprintf() */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for sleep() */



SocketMulticast::SocketMulticast() {
    s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s == -1){
        perror("SocketMulticast()->socket()");
        exit(EXIT_FAILURE);
    }
}

SocketMulticast::~SocketMulticast() {
    close(s);
}