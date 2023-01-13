
/*

    To Run this program use command: g++ -o program_name -pthread program_name.cpp

*/


#include <iostream>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

#define MAX_BUFFER_SIZE 10

int buffer[MAX_BUFFER_SIZE];
int buffer_count = 0;
sem_t sem_full, sem_empty;
pthread_mutex_t mutex;

void* producer(void* arg) {
    while (true) {
        int item = rand() % 100;
        sem_wait(&sem_empty); // wait for empty slot
        pthread_mutex_lock(&mutex);
        buffer[buffer_count++] = item;
        cout << "Produced item: " << item << endl;
        pthread_mutex_unlock(&mutex);
        sem_post(&sem_full); // signal for full slot
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    while (true) {
        sem_wait(&sem_full); // wait for full slot
        pthread_mutex_lock(&mutex);
        int item = buffer[--buffer_count];
        cout << "Consumed item: " << item << endl;
        pthread_mutex_unlock(&mutex);
        sem_post(&sem_empty); // signal for empty slot
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    sem_init(&sem_full, 0, 0);
    sem_init(&sem_empty, 0, MAX_BUFFER_SIZE);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&sem_full);
    sem_destroy(&sem_empty);
    pthread_mutex_destroy(&mutex);

    return 0;
}

/*

This program implements a solution for the producer-consumer
problem using threads and semaphores. The program uses a buffer
of fixed size (MAX_BUFFER_SIZE) to store the items produced by
the producer thread and consumed by the consumer thread.

Two semaphores are used in this program: one to keep track of
the number of empty slots in the buffer (sem_empty) and another
to keep track of the number of full slots in the buffer (sem_full).

A mutex is used to protect the shared buffer from concurrent
access by the producer and consumer threads.

The producer thread generates a random number between 0 and 99
and adds it to the buffer after waiting for an empty slot. The
consumer thread consumes an item from the buffer after waiting
for a full slot.

It is important to note that, the pthread_exit(NULL) and 
pthread_join(producer_thread, NULL) are used to exit the thread 
and wait for the thread to terminate so that the main process 
does not get terminated before the thread does.

Also, the sem_init() function is used to initialize the semaphores
and pthread_mutex_init() function is used to initialize the mutex.
And, sem_destroy() and pthread 

*/

