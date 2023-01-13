/*

Here is a C++ program that uses inter-process communication (IPC) mechanisms provided by the operating
system to send and receive messages between two processes. It demonstrates how one process (the sender)
can send messages to another process (the receiver), and how the receiver can receive and print the
messages in the same order.

*/

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>

int main() {
    int fd[2];
    pipe(fd);

    pid_t pid = fork();
    if (pid == 0) {
        // Receiver process
        close(fd[1]); // Close the write end of the pipe
        char recv_buf[256];
        for (int i = 0; i < 3; i++) {
            read(fd[0], recv_buf, sizeof(recv_buf));
            std::cout << recv_buf << std::endl;
        }
        close(fd[0]);
    } else {
        // Sender process
        close(fd[0]); // Close the read end of the pipe
        std::string messages[3] = {"Hello", "World", "!"};
        for (int i = 0; i < 3; i++) {
            write(fd[1], messages[i].c_str(), messages[i].length() + 1);
        }
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}

/*



In this program, the sender process uses the pipe() function to create a pipe,
which creates two file descriptors (fd[0] and fd[1]) that can be used to read
from and write to the pipe, respectively. Then, the sender process uses the fork()
function to create a new process (the receiver process). In the sender process, it
uses the write() function to write the messages into the pipe, and in the receiver
process, it uses the read() function to read the messages from the pipe. The
messages are read in the same order as they were written. And the program waits for
the child process to complete and exits.

This program uses pipe for interprocess communication, other IPC mechanisms such as
shared memory, message queues, and sockets could also be used to achieve the same 
goal depending on the use case.



*/
