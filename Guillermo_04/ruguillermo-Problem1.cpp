/* A program that identifies the highest and lowest number among three numbers
   and print their difference.
   CMSC 28- ComProg II: Object Oriented Programming
   Created by: Roslyn Faith Guillermo */

#include <iostream>

// Displays program description onscreen
void progdescription() {
    std::cout << "Teaser Problem: This program finds the highest and lowest numbers"
              << "\namong three input values, and prints their difference.\n\n";
    std::cout << "Programmed by: Roslyn Faith Guillermo"
			  << "\nDate done: April 27, 2024"
			  << "\nSubject: CMSC 28\n\n";
}

// Asks the user to input values of the three variables
void readdata(int& x, int& y, int& z) {
    std::cout << "Enter the value of x: ";
    std::cin >> x;
    std::cout << "Enter the value of y: ";
    std::cin >> y;
    std::cout << "Enter the value of z: ";
    std::cin >> z;
}

// Determines the highest among the three inputted variables
int getlarge(int x, int y, int z) {
    return (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
}

// Identifies the lowest among the three inputted variables
int getsmall(int x, int y, int z) {
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

// Displays the inputted values, the highest and lowest, and the difference.
void showdata(int x, int y, int z, int largeval, int smallval, int diff) {
    std::cout << "Inputted values: x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << "Highest value: " << largeval << std::endl;
    std::cout << "Smallest value: " << smallval << std::endl;
    std::cout << "Difference between the highest and lowest values: " << diff << std::endl;
}

int main() {
    // All variables are declared as integer
    int x, y, z, smallval, largeval, diff;

    // Function call to display the program description onscreen
    progdescription();

    // Function call to read the input values
    readdata(x, y, z);

    // Function call to identify the highest and the lowest value among the three
    smallval = getsmall(x, y, z);
    largeval = getlarge(x, y, z);

    // The assignment statement to get the difference between the highest and lowest value
    diff = largeval - smallval;

    // Function call to display all the values
    showdata(x, y, z, largeval, smallval, diff);

    return 0;
}
