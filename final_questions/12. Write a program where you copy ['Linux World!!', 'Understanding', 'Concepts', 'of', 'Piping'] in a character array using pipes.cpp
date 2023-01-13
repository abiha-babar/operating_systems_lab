#include <iostream>
#include <unistd.h>
#include <array>

int main() {
    std::array<std::string, 5> messages = {"Linux World!!", "Understanding", "Concepts", "of", "Piping"};

    // Create two pipes
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    // Fork a child process
    int pid = fork();

    if (pid == 0) {
        // Child process

        // Close the write end of pipe1
        close(pipe1[1]);

        // Read from pipe1 and write to pipe2
        char buffer[100];
        for (auto message : messages) {
            read(pipe1[0], buffer, message.size() + 1);
            write(pipe2[1], buffer, message.size() + 1);
        }
        // Close the read end of pipe1 and the write end of pipe2
        close(pipe1[0]);
        close(pipe2[1]);
    }
    else {
        // Parent process

        // Close the read end of pipe2
        close(pipe2[0]);

        // Write to pipe1 and read from pipe2
        char buffer[100];
        for (auto message : messages) {
            write(pipe1[1], message.c_str(), message.size() + 1);
            read(pipe2[0], buffer, message.size() + 1);
            std::cout << buffer << std::endl;
        }
        // Close the write end of pipe1 and the read end of pipe2
        close(pipe1[1]);
        close(pipe2[0]);
    }

    return 0;
}


/*
This program uses two pipes to copy elements of an array of strings 
from the parent process to the child process. The parent process writes
to pipe1, child process reads from pipe1 and writes to pipe2.
Parent process reads from pipe2 and print on screen.
*/
