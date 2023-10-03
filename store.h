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

void setKey(store *db, char *key, char *val);

void printDb(store *db);