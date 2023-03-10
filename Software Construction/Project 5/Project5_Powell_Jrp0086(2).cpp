// Please change the following comment part into you name
// #0#BEGIN# DO NOT MODIFY THIS COMMENT LINE!
// Firstname
// Lastname
// #0#END# DO NOT MODIFY THIS COMMENT LINE!

#include <stdio.h>
#include <pthread.h>
#include <iostream>
using namespace std;

#define MAX 10

pthread_mutex_t the_mutex;

pthread_cond_t condc, condp;

int buffer = 0;

void *producer(void *ptr) {

    int i;

    for(i = 1; i <= MAX; i++) {

        pthread_mutex_lock(&the_mutex);

        while(buffer != 0) pthread_cond_wait(&condp, &the_mutex);

        buffer = i * 7;

        cout << "producer produce item " << buffer << endl;

        pthread_cond_signal(&condc);

        pthread_mutex_unlock(&the_mutex);

    }
    pthread_exit(0);
    return 0;
}

void *consumer(void *ptr) {

    int i;
    int get_data;

    for(i = 1; i <= MAX; i++) {

        pthread_mutex_lock(&the_mutex);

        while(buffer != 0) pthread_cond_wait(&condc, &the_mutex);

        buffer = get_data;

        cout << "consumer consume item " << get_data << endl;

        buffer = 0;

        pthread_cond_signal(&condp);

        pthread_mutex_unlock(&the_mutex);
    }
    pthread_exit(0);
    return 0;
}

main(int argc, char *argv[]) {

    int banner_id = 904034209;

    cout << "Banner id: " << banner_id << endl;

    pthread_t pro, con;
    pthread_mutex_init(&the_mutex, 0);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);

    pthread_create(&con, 0, consumer, 0);
    pthread_create(&pro, 0, producer, 0);
    pthread_join(pro, 0);
    pthread_join(con, 0);

    //
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);

    return 0;
}





