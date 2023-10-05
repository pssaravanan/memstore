#include "server.h"
#include <stdio.h>

char buffer[1024] = { 0 };
int curr_pos = 0;

char * readline(client * c) {
    char res[1024];
    int i = 0;
    while(1) {
        if(curr_pos == 0 || curr_pos == 1024 || buffer[curr_pos] == '\0'){
            curr_pos = 0;
            read(c -> socketfd, &buffer, 1024);
        }
        res[i] = buffer[curr_pos++];
        if(res[i] == '\n'){
            return res;
        }
        i++;
    }
}

void processRequest(client * c) {
    while(1){
        printf("read: %s", readline(c));
    }
}
