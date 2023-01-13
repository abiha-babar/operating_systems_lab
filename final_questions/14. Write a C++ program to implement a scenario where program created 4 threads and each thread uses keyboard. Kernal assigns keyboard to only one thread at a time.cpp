/*

    INSTRUCTION TO RUN THIS PROGRAM
    
        g++ program_name.cpp -o output
        ./output

*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex keyboard_mutex;

void thread_function(int thread_num) {
    while (true) {
        keyboard_mutex.lock();
        std::cout << "Thread " << thread_num << " is using the keyboard." << std::endl;
        std::string input;
        std::cin >> input;
        std::cout << "Thread " << thread_num << " entered: " << input << std::endl;
        keyboard_mutex.unlock();
    }
}

int main() {
    std::thread thread1(thread_function, 1);
    std::thread thread2(thread_function, 2);
    std::thread thread3(thread_function, 3);
    std::thread thread4(thread_function, 4);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    return 0;
}


/*
This program creates 4 threads and uses a mutex to ensure that
only one thread can access the keyboard at a time.Threads try to 
acquire lock before using keyboard,if locked they wait till they
can acquire the lock.
*/
