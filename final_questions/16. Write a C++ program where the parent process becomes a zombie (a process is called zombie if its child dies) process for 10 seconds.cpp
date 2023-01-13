#include <iostream>
#include <unistd.h>

int main() {
    // Fork the process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        std::cout << "Child process ID: " << getpid() << std::endl;
        exit(0);
    }
    else {
        // Parent process
        std::cout << "Parent process ID: " << getpid() << std::endl;
        sleep(10);
    }
    return 0;
}


/*
This program creates a child process using the fork system call and the
child process exits immediately after it is created, while the parent
process sleeps for 10 seconds, during that time the child process is
already dead but the parent process is still waiting for the child process
to complete its execution, and thus the parent process becomes a zombie
process for 10 seconds, after that the parent process continues with its
execution.

A zombies process is a process whose execution is complete but still has
an entry in the process table, these processes are also known as "defunct"
processes. In most cases, the parent process is responsible for cleaning
up the child process's resources and exiting, however, in this example,
the parent process is not cleaning up the child process's resources and it
becomes a zombies process.

Please note that in real world scenario, it is not recommended to create
zombie process as it is not good for system performance, Instead process
should be cleaned up using wait() or waitpid() system calls.

*/