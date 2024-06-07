/* A program that finds the largest and smallest number and calculates the average, standard
  deviation, and variance from the data inputted by the user 
  CMSC 28- Computer Programming II */

#include <iostream> 
#include <cmath>
using namespace std;

const int MAX_SIZE = 10;

// Asks the user to input integers
void inputInteger(int num[], int& size) {
    size = 0; // Initialize the size of the array to 0
    int input; 
    
    // Loop to input integers until the maximum size is reached or until the user inputs 0
    while (size < MAX_SIZE) {
        cout << "Input an integer: ";
        cin >> input; // Reads the integer input from the user
        if (input == 0) break; // If the input is 0, exit the loop
        num[size++] = input; // Stores the input integer in the array and increment the size
    }
}

// Finds the largest integer in the array, returns 0 if array is empty
int find_Largest(const int num[], int size) {
    if (size == 0) return 0; // Return 0 if the array is empty
    
    int largest = num[0]; // Initialize the largest integer with the first element of the array
    
    // Loop through the array to find the largest integer
    for (int i = 1; i < size; ++i) {
        if (num[i] > largest) { // If the current element is larger than the current largest integer,
            largest = num[i];   // it updates the largest integer
        }
    }
    return largest;
}

// Finds the smallest integer in the array, returns 0 if array is empty
int find_Smallest(const int num[], int size) {
    if (size == 0) return 0; // Return 0 if the array is empty
    
    int smallest = num[0]; // Initialize the smallest integer with the first element of the array
    
    // Loop through the array to find the smallest integer
    for (int i = 1; i < size; ++i) {
        if (num[i] < smallest) { // If the current element is smaller than the current smallest integer,
            smallest = num[i];   // it updates the smallest integer
        }
    }
    return smallest;
}

// Calculates the average of the integers in the array
double calcAverage(const int num[], int size) {
    double sum = 0;
    
    // Loop through the array to calculate the sum of integers
    for (int i = 0; i < size; ++i) {
        sum += num[i]; // Adds each element to the sum
    }
    return sum / size; // Return the average by dividing the sum by the number of elements
}


// Calculates the variance of elements in the array
double calcVariance(const int num[], int size, double average) {
    double variance = 0;
    
    // Loop through the array to calculate the sum of squared differences from the average
    for (int i = 0; i < size; ++i) {
        variance += pow(num[i] - average, 2); // Add the squared difference from the average to the variance
    }
    return variance / size; // Return the variance by dividing the sum of squared differences by the number of elements
}

// Calculates the standard deviation
double calcSTDeviation(double variance) {
    return sqrt(variance); // Return the square root of the variance or the standard deviation
}

// Function to display the results
void displayOutput(int largest, int smallest, double average, double standardDeviation, double variance) {
    cout << "\nLargest: " << largest << endl; // largest number in the array
    cout << "Smallest: " << smallest << endl; // smallest number in the array
    cout << "Average: " << average << endl;   // average of the numbers in the array
    cout << "Standard Deviation: " << standardDeviation << endl; // the standard deviation of the numbers in the array
    cout << "Variance: " << variance << endl; // the variance of the numbers in the array
}

int main() {
    int num[MAX_SIZE];
    int size;
    double average = 0, variance = 0, standardDeviation = 0; // Initialize results to 0
    
    cout << "\t\t\tProgramming Exercise 05" << endl;
    cout << "\t\tSubmitted by: Roslyn Faith Guillermo" << endl;
    cout << "------------------------------------------------------------------------" << endl;
	cout << "  This program will ask the user to input various numbers (positive" << endl;
	cout << "or negative but not zero) and perform basic statistics on these numbers.\n" << endl;
	
    // Asks user to input integers
    inputInteger(num, size);	// Call function to input integers
    
    if (size != 0) { // If the user inputted at least one number
        // Calculates the required values
        average = calcAverage(num, size); // Call function to calculate average
        variance = calcVariance(num, size, average); // Call function to calculate variance
        standardDeviation = calcSTDeviation(variance); // Call function to calculate standard deviation
    }
    
    // Displays results
    displayOutput(find_Largest(num, size), find_Smallest(num, size), average, standardDeviation, variance); // Call function to display results

    return 0;
}

