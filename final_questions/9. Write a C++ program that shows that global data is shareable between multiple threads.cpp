/*

    INSTRUCTION TO RUN THIS PROGRAM
    
        g++ program_name.cpp -o output
        ./output

*/

#include <iostream>
#include <thread>

// Global variable
int sharedData = 0;

// Thread function that increments the global variable
void incrementData() {
    for (int i = 0; i < 100; i++) {
        sharedData++;
    }
}

int main() {
    std::cout << "Initial value of shared data: " << sharedData << std::endl;

    // Create two threads that increment the global variable
    std::thread firstThread(incrementData);
    std::thread secondThread(incrementData);

    // Wait for the threads to finish
    firstThread.join();
    secondThread.join();

    std::cout << "Final value of shared data: " << sharedData << std::endl;

    return 0;
}

/* 
This program creates two threads that increment a global variable.
The initial and final values of the variable are printed to the console
to demonstrate that the threads are able to share and update the global data.
Note that this is a simple example and in real world scenarios it may 
cause race conditions and other threading issues, So it is important to 
use thread synchronization mechanism like Mutex.
*/

