#include <iostream>
#include "Employees.h"

using namespace std;

int main() {
    string fname, lname, gender, email, cpNumber, empNum, position, office;
    double salary;
    
    cout << "\tThis program displays a congratulatory message for a job offer to a new employee along with providing"
         << " details \n\tnecessary with his/her employment. The details are inputted by the user/CEO of XYZ Inc." << endl;
    cout << "\tProgrammed by: Roslyn Faith Guillermo" << endl;
    
    // Asks user to input employee details
    cout << "\n\t-----------------------------------------------------------------------" << endl;
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

    cout << "\tEnter employee number: ";
    getline(cin, empNum);

    cout << "\tEnter position: ";
    getline(cin, position);

    cout << "\tEnter office: ";
    getline(cin, office);

    cout << "\tEnter salary: ";
    cin >> salary;
    cin.ignore();

    cout << "\t----------------------------------------------------------------------" << endl;

    // Create an Employees object using the default constructor
    Employees employee;
    employee.setFirstName(fname);
    employee.setLastName(lname);
    employee.setGender(gender);
    employee.setEmailAdd(email);
    employee.setCpNumber(cpNumber);
    employee.setEmpNum(empNum);
    employee.setPosition(position);
    employee.setOffice(office);
    employee.setSalary(salary);

    // Displays congratulatory messagae with inputted details
    cout << "\n\t==========================CONGRATULATIONS============================" << endl;
    cout << "\n\t" << employee.getFirstName() << " " << employee.getLastName() << ", " << employee.getGender() << endl;
    cout << "\t" << employee.getCpNumber() << endl;
    cout << "\t" << employee.getEmailAdd() << endl;
    cout << "\n\tDear " << employee.getFirstName() << "," << endl;
    cout << "\tAllow me to congratulate you on your new position as\n\t" << employee.getPosition() << " and part of the "
         << employee.getOffice() << ". Below are important details \n\tneeded as part of our family in XYZ Inc." << endl;
    cout << "\n\tYour Employee Number: " << employee.getEmpNum() << endl;
    cout << "\tYour Job Position and Office: " << employee.getPosition() << " of " << employee.getOffice() << endl;
    cout << "\tYour Monthly Salary: Php " << employee.getSalary() << endl;
    cout << "\n\tBest regards, \n\tCEO\n" << endl;
    cout << "\t=======================================================================" << endl;

    return 0;
}
