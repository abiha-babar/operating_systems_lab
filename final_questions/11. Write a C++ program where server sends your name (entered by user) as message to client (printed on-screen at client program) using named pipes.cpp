#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    // Create a named pipe (FIFO)
    int result = mkfifo("/tmp/my_pipe", 0666);

    // Open the named pipe for writing
    int pipe_fd = open("/tmp/my_pipe", O_WRONLY);

    // Write the message to the pipe
    write(pipe_fd, name.c_str(), name.size() + 1);
    std::cout << "Server: Sent message " << name << " to the client." << std::endl;

    // Close the pipe
    close(pipe_fd);

    return 0;
}


/*
This program uses named pipes (also known as FIFOs) to allow communication 
between the server and client programs. The user enters their name and the 
server program writes the name to the named pipe. The client program reads 
the name from the pipe and prints it on the screen. 
*/
