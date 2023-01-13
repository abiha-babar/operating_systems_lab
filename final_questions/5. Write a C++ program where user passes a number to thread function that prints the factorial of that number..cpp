/*

Write a C++ program where user passes a number to thread
function that prints the factorial of that number.

g++ program.cpp -o output
./output: &lt;integer value&gt;
./output -5
-5 must be &gt;=0
./output 5
factorial = 120

*/


// INSTRUCTION TO RUN THIS PROGRAM


/*

    To run this
        g++ program_name.cpp -o output
        ./output -5
        ./output 5

*/

#include <iostream>
#include <pthread.h>
#include <cstdlib>
using namespace std;

// Global variable to hold the number passed to the thread function
int number;

// Thread function to calculate the factorial of the passed number
void* factorial(void* arg) {
    int n = *((int*) arg);
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    cout << "Factorial = " << result << endl;
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "./output <integer value>" << endl;
        return 0;
    }
    number = atoi(argv[1]);
    if (number < 0) {
        cout << argv[1] << " must be >=0" << endl;
        return 0;
    }
    pthread_t thread;
    pthread_create(&thread, NULL, factorial, &number);
    pthread_join(thread, NULL);
    return 0;
}


/*

In this program, the main function takes an integer value as a 
command line argument and stores it in the global variable "number".
The program then creates a new thread, passing the address of the 
"number" variable to the thread function "factorial". 
The "factorial" function calculates the factorial of the passed number 
and prints the result. The main function waits for the thread to 
complete using the pthread_join() function.

In the command line, the program is compiled using the command 
"g++ program.cpp -o output" and executed by providing an integer value 
as an argument, for example "./output 5" will output the factorial of 
5 which is 120. The program also checks if the number passed is negative 
and shows a message accordingly.

It is important to note that, the pthread_exit(NULL) and pthread_join(thread, NULL) 
are used to exit the thread and wait for the thread to terminate so that the 
main process does not get terminated before the thread does.

*/
