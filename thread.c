#include "server.h"

void initialize_thread_pool(){
    t_pool.current_size = 0;
}

thread_id spawn_thread_and_process(void * _Nullable (* thread_func)(void * _Nullable), void * _Nullable args){
    thread_id t_id = t_pool.current_size;
    client * c = (client *) args;
    c -> t_id = t_id;
    pthread_create(&t_pool.pool[t_id], NULL, thread_func, c);
    t_pool.current_size++;
}

thread_id wait_for_thread(thread_id t_id){
     pthread_join(t_pool.pool[t_id], NULL);
}