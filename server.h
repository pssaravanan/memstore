#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include<stdlib.h>
#include "thread.h"
typedef struct {
    struct sockaddr_in address;
    int socketfd;
} server;

typedef struct {
    int socketfd;
    thread_id t_id;
} client;


server* createServer(uint32_t addr, int port, sa_family_t family);

client* acceptConnection(server *s);