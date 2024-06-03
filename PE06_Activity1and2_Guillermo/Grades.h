#include <iostream>
using namespace std;

class Grade {
    private:
        string Subject;
        int Grades;
    public:
        Grade() {}
        
        Grade(string newSubject, int newGrade) {
            Subject = newSubject;
            Grades = newGrade;
        }

        void setSubject(string newSubject) {
            Subject = newSubject;
        }
        
        string getSubject() {
            return Subject;
        }
        
        void setGrade(int newGrade) {
            Grades = newGrade;
        }

        void getGrade() {
        	cout << "Your Grade is: " << Grades << endl;
        	if(Grades >= 60 && Grades <= 100) {
                cout << "Congrats, You Passed!" << endl;
            } else if (Grades < 60 && Grades >= 0) {
                cout << "Better luck next time, You Failed." << endl;
            } else
            	cout << "Invalid Grade" << endl;
        }
        
        void view() {
            cout << "Subject is = " << Subject << endl;
            cout << "Your grade is = " << Grades << endl;
        }
};
