#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"rand.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "store.h"
#include "request.h"


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
    

    // printf("%s", test_rand_str(10));
    // int j = 0;
    // while(j <= 100000){
    //     char *key = rand_str(5);
    //     char *value = rand_str(10);
    //     setKey(db, key, value);
    //     j = j + 1;
    // }
    server *s = createServer(0, 8000, AF_INET);
    while(1){
        client *c = acceptConnection(s);
        spawn_thread_and_process(&processRequest, c);
    }
    printDb(db);
}