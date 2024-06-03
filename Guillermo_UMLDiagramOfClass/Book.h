#include <iostream>
using namespace std;

// Defining the class "Book"
class Book {
private: 
    string Title;
    string Author;
    string ISBN;
    string Publisher;

public: 
    // Constructors
    Book(string title, string author, string isbn, string publisher) {
        Title = title;
        Author = author;
        ISBN = isbn;
        Publisher = publisher;
    }

    // Getter to retrieve the title of the book
    string getTitle() {
        return Title;
    }

    // Getter method to retrieve the author of the book
    string getAuthor() {
        return Author;
    }

    // Getter to retrieve the ISBN of the book
    string getISBN() {
        return ISBN;
    }

    // Getter to retrieve the publisher of the book
    string getPublisher() {
        return Publisher;
    }

    // Setter method to set the title of the book
    void setTitle(string bktitle) {
        Title = bktitle;
    }

    // Setter to set the author of the book
    void setAuthor(string bkauthor) {
        Author = bkauthor;
    }

    // Setter to set the ISBN of the book
    void setISBN(string bkisbn) {
        ISBN = bkisbn;
    }

    // Setter to set the publisher of the book
    void setPublisher(string bkpublisher) {
        Publisher = bkpublisher;
    }
};
