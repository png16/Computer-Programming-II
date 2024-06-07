#include <string>

using namespace std;

class Person {
private:
    string fname, lname, gender;
    string emailAdd, cpNumber;

public:
    // Default constructor
    Person() : fname(""), lname(""), gender(""), emailAdd(""), cpNumber("") {}

    // Parameterized constructor
    Person(string newfname, string newlname, string newgdr, string newEmail, string newCpNumber) 
        : fname(newfname), lname(newlname), gender(newgdr), emailAdd(newEmail), cpNumber(newCpNumber) {}

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

    void setEmailAdd(const string &newEmail) { 
        emailAdd = newEmail; 
    }

    void setCpNumber(const string &newCpNumber) { 
        cpNumber = newCpNumber; 
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

    string getEmailAdd() const { 
        return emailAdd; 
    }

    string getCpNumber() const { 
        return cpNumber; 
    }
};

