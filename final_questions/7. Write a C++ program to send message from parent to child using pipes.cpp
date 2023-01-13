#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

int main() {
    // Create the pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        cout << "Pipe creation failed" << endl;
        return 1;
    }

    // Fork a new process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        // Close the write end of the pipe
        close(pipefd[1]);

        // Read from the pipe
        char buffer[100];
        int n = read(pipefd[0], buffer, 100);
        buffer[n] = '\0';
        cout << "Child process: Received message - " << buffer << endl;

        // Close the read end of the pipe
        close(pipefd[0]);
    } else {
        // Parent process
        // Close the read end of the pipe
        close(pipefd[0]);

        // Write to the pipe
        const char* message = "Hello child!";
        write(pipefd[1], message, strlen(message));

        // Close the write end of the pipe
        close(pipefd[1]);
    }
    return 0;
}

/*
In this program, a pipe is created using the pipe() system call. 
The pipe is a unidirectional communication channel between the 
parent and child process. The pipe has two file descriptors, 
one for reading and one for writing.

The program then forks a new process using the fork() system call.

In the child process, the read end of the pipe is closed, 
then the child reads from the pipe and prints the message received 
from the parent process. Then it closes the read end of the pipe.

In the parent process, the write end of the pipe is closed, 
then the parent writes a message to the pipe and sends it to the child process. 
Then it closes the write end of the pipe.

It is important to note that, the parent process and child process 
execute concurrently and communicate with each other using the pipe.

*/

