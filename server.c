#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>
#include "server.h"


server* createServer(uint32_t addr, int port, sa_family_t family){
    server *s = (server *)malloc(sizeof(server));
    int new_socket, valread;
    int addrlen = sizeof(s -> address);
    char buffer[1024] = { 0 };
    if((s -> socketfd = socket(family, SOCK_STREAM, 0)) < 0){
        perror("socket failure");
        exit(EXIT_FAILURE);
    }
    s -> address.sin_addr.s_addr = addr;
    s -> address.sin_port =  htons(port);
    s -> address.sin_family = family;
    if (bind(s -> socketfd, (struct sockaddr*)&s->address,
             sizeof(s -> address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(s -> socketfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    return s;
}
