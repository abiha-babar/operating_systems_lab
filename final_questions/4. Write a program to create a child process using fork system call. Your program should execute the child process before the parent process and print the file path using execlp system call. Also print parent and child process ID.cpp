#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    // Create a child process
    pid_t pid = fork();
    if (pid == 0) {
        // This is the child process
        cout << "Child process ID: " << getpid() << endl;
        execlp("/bin/ls", "ls", "-l", "-a", NULL);
    } else {
        // This is the parent process
        cout << "Parent process ID: " << getpid() << endl;
    }
    return 0;
}

/*

In this program, the fork() system call is used to create a child 
process. The fork() function returns the child process ID in the 
parent process and 0 in the child process. The program uses this 
return value to determine whether it is running in the parent or 
child process.

In the child process, the execlp() system call is used to execute 
the "ls" command with the "-l" and "-a" options, which will print 
the file path in the current directory.

The parent process will print its own process ID.

It is important to note that execlp() function replaces the current 
process image with a new process image, so the code after the 
execlp() call will not be executed.

Also, make sure that the command you are trying to execute is 
present in the system and the path is correct.

*/
