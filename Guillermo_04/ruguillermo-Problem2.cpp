/* A program that converts an integer value to its binary equivalent
   CMSC 28- ComProg II: Object Oriented Programming
   Created by: Roslyn Faith Guillermo */

#include <iostream>
#include <string>

// Displays the program description onscreen
void progdescription() {
    std::cout << "Boredom Reliever Problem: This program converts an integer to its binary equivalent.\n";
    std::cout << "\nProgrammed by: Roslyn Faith Guillermo"
			  << "\nDate done: April 27, 2024"
			  << "\nSubject: CMSC 28\n\n";
}

// Asks the user to input an integer value
void input_data(int& dataInt) {
    std::cout << "Enter an integer: ";
    std::cin >> dataInt;
}

// User-defined function that converts the integer value to binary
long long decimalToBinary(int dataInt) {
    // Initialize binary number and base for binary place value
    long long binary = 0;
    long long base = 1;

    // Handle negative numbers
    bool isNegative = false;
    if (dataInt < 0) {
        isNegative = true;
        dataInt = -dataInt; // Convert negative number to positive for conversion
    }

    // Convert decimal to binary
    while (dataInt > 0) {
        int remainder = dataInt % 2; // Gets the remainder when dividing by 2 as it is the base number of binary number system
        
        binary += remainder * base; // Multiply remainder by current base and add to binary number
        
        base *= 10; // Moves to the next binary place value by multiplying the base by 10
        
        dataInt /= 2; // Updates the decimal number for next iteration
    }

    // If the original input was negative, convert the binary back to negative
    if (isNegative) {
        binary *= -1;
    }
    
    return binary; // Returns the binary representation
}

// Displays the inputted value and its binary equivalent
void display_data(int dataInt, long long binary_eq) {
    std::cout << "\nInteger value: " << dataInt << std::endl;
    std::cout << "Binary equivalent: " << binary_eq << std::endl;
}

int main() {
    // Variable declaration
    int dataInt;
    long long binary_eq; //holds larger integer values compared to int

    // Call to display program description
    progdescription();

    // Call to read user-input value
    input_data(dataInt);

    // Converts decimal to binary
    binary_eq = decimalToBinary(dataInt);

    // Calls the function to display the values
    display_data(dataInt, binary_eq);

    return 0;
}


