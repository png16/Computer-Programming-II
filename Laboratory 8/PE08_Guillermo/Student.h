#include "Person.h"

using namespace std;

class Student : public Person {
private:
    string studentNum;

public:
    string Course;
    string Department;
    string College;

    // Default constructor
    Student() {}

    // Setters
    void setStudentNum(const string &newStudentNum) {
        studentNum = newStudentNum;
    }
    
	void setCourse(const string &newCourse) {
	    Course = newCourse;
	}
	
	void setDepartment(const string &newDepartment) {
	    Department = newDepartment;
	}
	
	void setCollege(const string &newCollege) {
	    College = newCollege;
	}
	
    // Getters
    string getStudentNum() const {
        return studentNum;
    }
    
    string getCourse() const {
        return Course;
    }

    string getDepartment() const {
        return Department;
    }

    string getCollege() const {
        return College;
    }
};

