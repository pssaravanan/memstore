#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define HASH_IN_SIZE 1000

struct _dataitem {
    char *key;
    char *val;
    int expiry;
    struct _dataitem *next;
};

typedef struct _dataitem dataitem;


typedef struct {
    dataitem *hash_table[HASH_IN_SIZE];
} store;


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

void setKey(store *db, char *key, char *val) {
    dataitem *item = (dataitem *)malloc(sizeof(dataitem));
    item -> key = key;
    item -> val = val;
    int keyPos = hashfunc(key) % HASH_IN_SIZE;
    dataitem *existing = db->hash_table[keyPos];
    db->hash_table[keyPos] = item;
    item -> next = existing;
    printf("%d,%s,%s\n", keyPos, item->key, item->val);
}

void printDb(store *db){
    int i =0;
    FILE *fptr;
    fptr = fopen("./db.txt", "w");
    fprintf(fptr, "pos,key,val\n");
    while(db->hash_table[i] != NULL) {
        dataitem *curr = db -> hash_table[i];
        printf("writing index: %d", i);
        while(curr != NULL) {
            fprintf(fptr, "%d,%s,%s\n", i, curr -> key, curr -> val);
            curr = curr->next;
        }
        i = i + 1;
    }
    fclose(fptr);
}

int main(int argc, char *argv[]){

    store *db = (store *)malloc(sizeof(store));
    printf("%ld,%ld,%ld, %d", sizeof(db -> hash_table), sizeof(char *), sizeof(int), db->hash_table[0] == NULL);
    srand((unsigned) time(&t));

    int j = 0;
    while(j <= 100000){
        char *key = rand_str(5);
        char *value = rand_str(10);
        setKey(db, key, value);
        j = j + 1;
    }
    printf("Added keys\n");
    printDb(db);
}