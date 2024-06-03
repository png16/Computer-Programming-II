#include <iostream>
#include "Person.h"
#include "Grades.h"
using namespace std;

int main(){
	int a, Grades;
	char g;
	string Subject;
	Person p;
	Grade G;

	cout << "Input age: ";
	cin >> a;
	p.setage(a);

	cout << "Input gender: ";
	cin >> g;
	p.setgender(g);
	
	cout << "Input grade: ";
	cin >> Grades;
	G.setGrade(Grades);
	
	cin.ignore();
    cout << "Input subject: ";
    getline(cin, Subject);
    G.setSubject(Subject);
    
	cout << "\nYour Age is: " << p.getage()  << endl;
	cout << "Your Gender is: " << p.getgender()  << endl;
	cout << "Your Subject is: " << G.getSubject()  << endl;
	G.getGrade();
	

	return 0;
}
