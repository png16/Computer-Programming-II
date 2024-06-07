#include <string>

using namespace std;

class Person {
    private:
        string fname, lname, gender;

    public:
        // Initializes member variables to empty strings
        Person() : fname(""), lname(""), gender("") {}

        // Initializes member variables with given values
        Person(string newfname, string newlname, string newgdr) 
            : fname(newfname), lname(newlname), gender(newgdr) {}

        // Setters
        void setFirstName(const string &newfname) { 
            fname = newfname; 
        }

        void setLastName(const string &newlname) { 
            lname = newlname; 
        }

        void setGender(const string &newgdr) { 
            gender = newgdr; 
        }

        // Getters
        string getFirstName() const { 
            return fname; 
        }

        string getLastName() const { 
            return lname; 
        }

        string getGender() const { 
            return gender; 
        }
};
