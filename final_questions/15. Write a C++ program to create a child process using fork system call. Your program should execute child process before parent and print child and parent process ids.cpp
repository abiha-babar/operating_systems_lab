#include <iostream>
#include <unistd.h>

int main() {
    // Fork the process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        std::cout << "Child process ID: " << getpid() << std::endl;
    }
    else {
        // Parent process
        std::cout << "Parent process ID: " << getpid() << std::endl;
    }
    return 0;
}

/*
This program creates a child process using fork system call.
It prints child process id before parent process id.
Both child and parent process run independently and have 
their own memory space and process id.
*/
