/*

    INSTRUCTION TO RUN THIS PROGRAM
    
        g++ program_name.cpp -o output
        ./output

*/

#include <iostream>
#include <pthread.h>
using namespace std;

// Function to be executed by the threads
void* thread_func(void* arg) {
    int id = *((int*)arg);
    cout << "Thread " << id << " is running on core " << sched_getcpu() << endl;
    return NULL;
}

int main() {
    // Create multiple threads
    int num_threads = 4;
    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/*
In this program, multiple threads are created using the 
pthread_create() function. Each thread is assigned a unique ID, 
which is passed as a parameter to the thread function. 
The thread function uses the sched_getcpu() function to obtain the 
ID of the core on which it is currently running. 
The function prints the thread ID and the core ID.

When the program is executed on a multicore system, different threads 
may be executed on different cores. It is important to note that the 
scheduling of threads is determined by the operating system and may 
vary depending on the specific system configuration and other factors.

It is important to notice that, if you are running the program on 
a single core system, the function sched_getcpu() will return -1

Also, it is important to note that, the pthread_join(thread, NULL) 
is used to wait for the thread to terminate so that the main 
process does not get terminated before the thread does.
*/

