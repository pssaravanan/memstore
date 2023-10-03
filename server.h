#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include<stdlib.h>
typedef struct {
    struct sockaddr_in address;
    int socketfd;
} server;

server* createServer(uint32_t addr, int port, sa_family_t family);