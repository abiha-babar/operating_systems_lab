#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    int id;
    string name;
    float cgpa;

    execl("/path/to/other/program", "other_program", &id, &name, &cgpa, NULL);

    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}


/*

This program uses the execl() function to execute another program 
and pass variables as arguments. The user is prompted to enter the 
name of the other program. The execl() function is then used to 
execute the other program located at /home/user/Desktop/ with the 
name entered by the user. The variables id, name, and cgpa are passed 
as arguments to the other program, and the other program should be 
designed to accept these variables as arguments and modify their values.
After the other program has been executed, the current program will 
print the values of id, name, and cgpa that were passed by the other 
program.

It is important to mention that the execl() function replaces the 
current process image with a new process image. This means that the 
execution of the current program is stopped, and the execution of the 
other program begins. Therefore, any code written after the execl() 
function call will not be executed.

*/
