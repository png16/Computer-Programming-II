#include <string>
#include <vector>
#include "Person.h"

using namespace std;

class Movie {
    private:
        string title, synopsis, mpaaRating, genre;                  
        vector<Person> directors; // List of directors
        vector<Person> actors;   // List of main actors/actresses

    public:
        // Initializes the movie attributes to empty strings
        Movie() : title(""), synopsis(""), mpaaRating(""), genre("") {}

        // Setters
        void setTitle(const string &newTitle) {
            title = newTitle; 
        }

        void setSynopsis(const string &newSyn) {
            synopsis = newSyn; 
        }

        void setMPAARating(const string &rating) { 
            mpaaRating = rating; 
        }

        void setGenre(const string &newGn) { 
            genre = newGn; 
        }

        // Adds a director to the list of directors
        void addDirector(const Person &d) { 
            directors.push_back(d); // vector's push_back function to add the director to the list
        }

        // Adds an actor to the list of actors
        void addActor(const Person &a) { 
            actors.push_back(a);   // vector's push_back function to add the actor to the list
        }

        // Getters
        string getTitle() const { 
            return title; 
        }

        string getSynopsis() const { 
            return synopsis; 
        }

        string getMPAARating() const { 
            return mpaaRating; 
        }

        string getGenre() const { 
            return genre; 
        }

        vector<Person> getDirectors() const { 
            return directors; 
        }

        vector<Person> getActors() const { 
            return actors; 
        }
};

