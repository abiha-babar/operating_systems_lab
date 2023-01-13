#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string input1, input2, input3;

    std::cout << "Enter the first string: ";
    std::cin >> input1;
    std::cout << "Enter the second string: ";
    std::cin >> input2;
    std::cout << "Enter the third string: ";
    std::cin >> input3;

    // Open a file for writing
    std::ofstream file("strings.txt");

    // Write the input strings to the file
    file << input1 << std::endl;
    file << input2 << std::endl;
    file << input3 << std::endl;

    file.close();

    // Open the file for reading
    std::ifstream fileIn("strings.txt");

    // Read the strings from the file and print them on the console
    std::string line;
    while (getline(fileIn, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    fileIn.close();

    return 0;
}


/*
This program takes three strings input from user and writes them 
in a file using ofstream. It also reads all strings from file using
ifstream and print on console.
*/
