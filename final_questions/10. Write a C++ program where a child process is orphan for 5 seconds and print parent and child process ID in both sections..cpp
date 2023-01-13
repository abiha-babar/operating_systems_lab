#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "Parent process ID: " << getpid() << std::endl;

    // Fork a child process
    int pid = fork();

    if (pid == 0) {
        std::cout << "Child process ID: " << getpid() << std::endl;

        // Make the child process orphan for 5 seconds
        if (setsid() < 0) {
            perror("setsid error");
            return 1;
        }
        std::cout << "Child process is orphaned for 5 seconds" << std::endl;
        sleep(5);
    }
    else {
        std::cout << "Parent process ID: " << getpid() << " after child process creation" << std::endl;
    }

    return 0;
}

/*
This program creates a child process using the fork() function, 
then the child process becomes an orphan by calling setsid() function
which creates a new session and the process group ID is set to the child's 
process ID. So the child process will not have a parent process for 5 secs
and the main parent process will be able to continue its execution.
The program prints the process ID of both the parent and child process 
before and after the child process is orphaned.
*/
