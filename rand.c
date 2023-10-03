#include<time.h>
#include<stdlib.h>

char *chs = "abcdefghijklmnopqrstuvwxyz";
time_t t;

char* rand_str(int len){
    srand((unsigned) time(&t));
    char *res = malloc (sizeof (char) * len);
    for(int i=0; i< len; i++){
        res[i] = rand() % 62;
    }
    return res;
}