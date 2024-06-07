#include "Person.h"

using namespace std;

class Employees : public Person {
private:
    string empNum;

public:
    string Position;
    string Office;
    double Salary;

    // Default constructor
    Employees() {}

    // Setters
    void setEmpNum(const string &newEmpNum) {
        empNum = newEmpNum;
    }
    
	void setPosition(const string &newPosition) {
	    Position = newPosition;
	}
	
	void setOffice(const string &newOffice) {
        Office = newOffice;
    }
	
	void setSalary(double newSalary) {
        Salary = newSalary;
    }

    // Getters
    string getEmpNum() const {
        return empNum;
    }

    string getPosition() const {
        return Position;
    }

    string getOffice() const {
        return Office;
    }

    double getSalary() const {
        return Salary;
    }
};
