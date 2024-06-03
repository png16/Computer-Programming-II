#include <iostream>
#include "Book.h" // Include the Book class header file
using namespace std;

int main() {
    // Create an instance of the Book class
    Book myBook("Divergent", "Veronica Roth", "9780062387240", "HarperCollins");

    // Display initial book information
    cout << "Title: " << myBook.getTitle() << endl;
    cout << "Author: " << myBook.getAuthor() << endl;
    cout << "ISBN: " << myBook.getISBN() << endl;
    cout << "Publisher: " << myBook.getPublisher() << endl;
    
    cout << "\nUpdated Book Details:" << endl;

    // Set and display the new title
    myBook.setTitle("The Maze Runner");
    cout << "New Title: " << myBook.getTitle() << endl;

    // Set and display the new author
    myBook.setAuthor("James Dashner");
    cout << "New Author: " << myBook.getAuthor() << endl;

    // Set and display the new ISBN
    myBook.setISBN("9781909489400");
    cout << "New ISBN: " << myBook.getISBN() << endl;
    
    // Set and display the new publisher
    myBook.setPublisher("Delacorte Press");
    cout << "New Publisher: " << myBook.getPublisher() << endl;
    
    return 0;
}

