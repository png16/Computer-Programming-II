#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    string fname, lname, gender, email, cpNumber, studentNum, course, department, college;

    cout << "\tThis program displays an admission notice for a new student by providing"
         << " \n\tthe necessary details crucial to his/her stay in UP Mindanao.\n\tThe details are user-input." << endl;
    cout << "\tProgrammed by: Roslyn Faith Guillermo" << endl;

    // Asks user to input student details
    cout << "\t----------------------------------------------------------------------------------------------------" << endl;
    cout << "\tEnter first name: ";
    getline(cin, fname);

    cout << "\tEnter last name: ";
    getline(cin, lname);

    cout << "\tEnter gender: ";
    getline(cin, gender);

    cout << "\tEnter email address: ";
    getline(cin, email);

    cout << "\tEnter contact number: ";
    getline(cin, cpNumber);

    cout << "\tEnter student number: ";
    getline(cin, studentNum);

    cout << "\tEnter degree program: ";
    getline(cin, course);

    cout << "\tEnter department: ";
    getline(cin, department);

    cout << "\tEnter college: ";
    getline(cin, college);

    cout << "\t----------------------------------------------------------------------------------------------------" << endl;

    // Create a Student object using the default constructor
    Student student;
    student.setFirstName(fname);
    student.setLastName(lname);
    student.setGender(gender);
    student.setEmailAdd(email);
    student.setCpNumber(cpNumber);
    student.setStudentNum(studentNum);
    student.setCourse(course);
    student.setDepartment(department);
    student.setCollege(college);

    // Displays admission notice to the student with the details inputted by the user
    cout << "\n\t=======================================CONGRATULATIONS=============================================" << endl;
    cout << "\n\t" << student.getFirstName() << " " << student.getLastName() << ", " << student.getGender() << endl;
    cout << "\t" << student.getCpNumber() << endl;
    cout << "\t" << student.getEmailAdd() << endl;
    cout << "\n\tGreetings, " << student.getFirstName() << " " << student.getLastName() << "!" << endl;
    cout << "\n\tWelcome to UP Mindanao and congratulations!" << endl;
    cout << "\n\tWe are pleased to inform you that you are admitted in the " << student.getCourse() << "\n\tprogram "
	     << "under the " << student.getDepartment() << ", "
         << "College of " << student.getCollege() << "." << endl;
    cout << "\n\tStudent Number: " << student.getStudentNum() << endl;
    cout << "\tUP Email Address: " << student.getEmailAdd() << endl;
    cout << "\tDegree Program: " << student.getCourse() << endl;
    cout << "\n\tSee you in campus, " << student.getFirstName() << "!" << endl;
    cout << "\t=====================================================================================================" << endl;

    return 0;
}


