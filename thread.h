#include<pthread.h>

#define THREAD_POOL_SIZE 1000

typedef struct {
    pthread_t * pool[THREAD_POOL_SIZE];
    int current_size;
} thread_pool;

typedef int thread_id;

thread_pool t_pool;

thread_id spawn_thread_and_process(void * _Nullable (* thread_func)(void * _Nullable), void * _Nullable args);

thread_id wait_for_thread(thread_id t_id);