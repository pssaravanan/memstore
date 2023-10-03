#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"rand.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "server.h"
#include "store.h"


int hashfunc(char *key) {
    return (int)key[0] - 97;
}

char *chs = "abcdefghijklmnopqrstuvwxyz";
time_t t;

char* rand_str(int len){
    char *res = malloc (sizeof (char) * len);
    for(int i=0; i< len; i++){
        res[i] = chs[rand() % 26];
    }
    res[len] = '\0';
    return res;
}


int main(int argc, char *argv[]){

    store *db = (store *)malloc(sizeof(store));
    printf("%ld,%ld,%ld, %d", sizeof(db -> hash_table), sizeof(char *), sizeof(int), db->hash_table[0] == NULL);
    srand((unsigned) time(&t));
    char buffer[1024] = { 0 };

    // printf("%s", test_rand_str(10));
    // int j = 0;
    // while(j <= 100000){
    //     char *key = rand_str(5);
    //     char *value = rand_str(10);
    //     setKey(db, key, value);
    //     j = j + 1;
    // }
    server *s = createServer(0, 8000, AF_INET);
    client *c = acceptConnection(s);
    read(c -> socketfd, &buffer, 1024);
    printf("read %s \n", buffer);
    printDb(db);
}