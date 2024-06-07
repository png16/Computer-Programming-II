/* A program using class hierarchy for managing products in a store's inventory
   Programmed by: Roslyn Faith Guillermo
   CMSC 28- Computer Programming II */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "ProductInventory.h" // Include the header file that contains the class definitions
using namespace std;

// Checks if the input is a double or not
double getDoubleInput(const string& prompt, bool allowDecimal = false) {
    double value;
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        if (!(ss >> value) || (ss >> ws).peek() != EOF || (!allowDecimal && value != static_cast<int>(value))) {
            cout << "Invalid value. Please input again." << (allowDecimal ? "." : "") << "." << endl;
        } else {
            return value;
        }
    }
}

// Only accepts positive value from the user
int getPositiveIntInput(const string& prompt) {
    int value;
    while (true) {
        value = static_cast<int>(getDoubleInput(prompt));
        if (value <= 0) {
            cout << "Invalid input. Please enter a positive integer greater than zero." << endl;
        } else {
            return value;
        }
    }
}

int main() {
    // Creates instances of Clothing and Electronics
    string name, brand, description, size, color, category, material, model, techSpecifications;
    double price, warranty;
    
    // Displays program information
    cout << "\tA program designed to display store product details from user-input.\n";
    cout << "\t\t      Programmed by:  Roslyn Faith Guillermo\n\n";

    // Input for Clothing
    cout << "INPUT DETAILS FOR CLOTHING PRODUCT:\n";
    cout << "Name: "; getline(cin, name);
    cout << "Brand: "; getline(cin, brand);
    price = getDoubleInput("Price: ", true);
    int quantity = getPositiveIntInput("Quantity: ");
    cout << "Description: "; getline(cin, description);
    cout << "Size: "; getline(cin, size);
    cout << "Color: "; getline(cin, color);
    cout << "Category: "; getline(cin, category);
    cout << "Material: "; getline(cin, material);

    Clothing shirt(name, brand, price, quantity, description, size, color, category, material);

    // Input for Electronics
    cout << "\nINPUT DETAILS FOR ELECTRONICS PRODUCT:\n";
    cout << "Name: "; getline(cin, name);
    cout << "Brand: "; getline(cin, brand);
    price = getDoubleInput("Price: ", true);
    quantity = getPositiveIntInput("Quantity: ");
    cout << "Description: "; getline(cin, description);
    cout << "Size: "; getline(cin, size);
    cout << "Color: "; getline(cin, color);
    cout << "Category: "; getline(cin, category);
    cout << "Model: "; getline(cin, model);
    warranty = getDoubleInput("Warranty (months): ", true);
    cout << "Technical Specifications: "; getline(cin, techSpecifications);

    Electronics electronics(name, brand, price, quantity, description, size, color, category, model, warranty, techSpecifications);

    // Prints the details of each product
    cout << "\n\t=======================================\n";
    cout << "\tHere are the details for your products:\n";
    cout << fixed << setprecision(2); // Set precision for printing prices
    cout << "\tCLOTHING PRODUCT:\n";
    shirt.printDetails();

    cout << "\n\tELECTRONICS PRODUCT:\n";
    electronics.printDetails();

    return 0;
}
