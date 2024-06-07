/* A program that asks users details about a movie with the use of vector implementation, classes, and instances
   Programmed by: Roslyn Faith Guillermo
   CMSC 28- Computer Programming II */

#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"

using namespace std;

// Prints the synopsis in right-justified by breaking it into lines with a width of 50
void printWithTab(const string& text, int lineWidth) {
    int length = text.length();
    int start = 0;

    while (start < length) {
        cout << "\t";
        int end = min(start + lineWidth, length);
        int nextStart = end;

        // Ensure to not break words in half
        if (end < length && text[end] != ' ') {
            while (end > start && text[end] != ' ') {
                end--;
            }
            if (end == start) {
                end = nextStart;
            }
        }

        cout << text.substr(start, end - start) << endl;
        start = end;

        // Skip any spaces at the start of the next line
        while (start < length && text[start] == ' ') {
            start++;
        }
    }
}

int main() {
    Movie movie;        // Creates the Movie object
    Person person;      // Creates the Person object
    string input;       // Stores the input from the user
    int numDirectors, numActors; // Variable for the number of directors and actors

    cout << "This program is designed for users to input details about a movie." << endl;
    cout << "Programmed by: Roslyn Faith Guillermo\n" << endl;

    // Input movie details
    cout << "Enter Movie Title: ";
    getline(cin, input); 
    movie.setTitle(input); 

    cout << "\nEnter Synopsis: ";
    getline(cin, input);    
    movie.setSynopsis(input);

    cout << "\nWhat is its MPAA Rating?: ";
    getline(cin, input);
    movie.setMPAARating(input);

    cout << "\nWhat is the Genre?: ";
    getline(cin, input);   
    movie.setGenre(input);

    cout << "\nHow many directors are there?: ";
    cin >> numDirectors; 
    cin.ignore();   // Clears the newline character from the buffer

    for (int i = 0; i < numDirectors; ++i) {
        cout << "Enter details for Director #" << (i + 1) << endl;

        cout << "First Name: ";
        getline(cin, input);
        person.setFirstName(input);

        cout << "Last Name: ";
        getline(cin, input);
        person.setLastName(input);

        cout << "Gender: ";
        getline(cin, input); 
        person.setGender(input); 

        movie.addDirector(person);  // Adds the director details to the movie class
    }

    cout << "\nHow many main actors/actresses are there? ";
    cin >> numActors; 
    cin.ignore();

    for (int i = 0; i < numActors; ++i) {
        cout << "Enter details for Actor/Actress #" << (i + 1) << endl;

        cout << "First Name: ";
        getline(cin, input);
        person.setFirstName(input); 

        cout << "Last Name: ";
        getline(cin, input);
        person.setLastName(input);

        cout << "Gender: ";
        getline(cin, input);  
        person.setGender(input); 

        movie.addActor(person);  // Add the actor/actress details to the movie class
    }

    // Displays the movie details
    cout << "\t=================================================" << endl;
    cout << "\t\t\tMOVIE DETAILS" << endl;
    cout << "\t=================================================" << endl;
    cout << "\tMovie Title: " << movie.getTitle() << endl;
    cout << "\t-------------------------------------------------" << endl;
    cout << "\tSynopsis: " << endl;
    printWithTab(movie.getSynopsis(), 50);
    cout << "\t-------------------------------------------------" << endl;
    cout << "\tMPAA Rating: " << movie.getMPAARating() << endl;
    cout << "\t-------------------------------------------------" << endl;
    cout << "\tGenre: " << movie.getGenre() << endl;
    cout << "\t-------------------------------------------------" << endl;
    
    cout << "\tDirector/s: " << endl;
    // A loop that displays the list of directors and their gender
    for (const auto &director : movie.getDirectors()) {
        cout << "\t  " << director.getFirstName() << " " << director.getLastName() << " (" << director.getGender() << ")" << endl;
    }
    cout << "\t-------------------------------------------------" << endl;
    cout << "\tMain Actor/s: " << endl;
    // A loop that displays the list of actors/actresses and their gender
    for (const auto &actor : movie.getActors()) {
        cout << "\t  " << actor.getFirstName() << " " << actor.getLastName() << " (" << actor.getGender() << ")" << endl;
    }
    cout << "\t-------------------------------------------------" << endl;

    return 0;
}

/* References: 
    https://stackoverflow.com/questions/5201619/right-justifying-output-stream-in-c
    https://www.cs.odu.edu/~zeil/cs361/latest/Public/vectorImpl/index.html
    chat.openai.com */
