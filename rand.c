#include<time.h>
#include<stdlib.h>

char *chs1 = "abcdefghijklmnopqrstuvwxyz";
time_t tt;

char* test_rand_str(int len){
    srand((unsigned) time(&tt));
    char *res = malloc (sizeof (char) * len);
    for(int i=0; i< len; i++){
        res[i] = rand() % 62;
    }
    return res;
}