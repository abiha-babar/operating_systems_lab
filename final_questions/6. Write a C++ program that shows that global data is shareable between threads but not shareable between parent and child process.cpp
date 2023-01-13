/*

    INSTRUCTION TO RUN THIS PROGRAM
    
        g++ program_name.cpp -o output
        ./output

*/

#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

// Global variable
int global_var = 0;

// Thread function
void* thread_func(void* arg) {
    for (int i = 0; i < 5; i++) {
        global_var++;
        cout << "Thread value: " << global_var << endl;
        sleep(1);
    }
    return NULL;
}

int main() {
    // Create a new thread
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);

    // Fork a new process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        for (int i = 0; i < 5; i++) {
            global_var++;
            cout << "Child process value: " << global_var << endl;
            sleep(1);
        }
    } else {
        // Parent process
        for (int i = 0; i < 5; i++) {
            global_var++;
            cout << "Parent process value: " << global_var << endl;
            sleep(1);
        }
    }
    pthread_join(thread, NULL);
    return 0;
}


/*
This program demonstrates that global data is shareable between threads 
but not shareable between parent and child process. It uses a global 
variable "global_var" which is initialized to 0. 
The program creates a new thread and a new process using the 
pthread_create() and fork() system calls respectively.

The thread function increments the value of the global variable by 1 
and prints the value 5 times with a delay of 1 second. Similarly, 
the parent and child process increments the global variable and prints 
the value 5 times with a delay of 1 second.

It is important to note that, the global variable is shared among the 
threads and all the threads increment the value of the global variable
and print the same value. However, the parent and child process have 
their own copy of the global variable, after the fork() system call
and both the processes increment their own copy of the global variable
and print different values.

Finally, the main function waits for the thread to complete using the 
pthread_join() function before exiting.
*/
