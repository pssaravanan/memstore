#include "store.h"
#include <stdio.h>
#include <stdlib.h>

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
