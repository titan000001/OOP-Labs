#include<bits/stdc++.h>
using namespace std;

class Student{
public: 
    string name;
    string rollNumber;

    Student(){}
    Student(const string& rName, const string& rRollNumber)
        : name(rName), rollNumber(rRollNumber){}

    virtual ~Student(){}

    virtual void displayDetails() const{
        cout << "Name of the student: " << name << endl;
        cout << "Roll No. " << rollNumber << endl;
    }
};

class Test{
public:
    int mark;
    char grade;

    Test(){}
    Test(int rMark, char rGrade) 
        : mark(rMark), grade(rGrade){}
    
    virtual ~Test(){}

    virtual void displayDetails() const{
        cout << "Obtained marks: " << mark << endl;
        cout << "Obtained grades: " << grade << endl;
    }
};

class studentPerformance : public Student , public Test{
public:
    studentPerformance(){}

    void inputName(string rName){
        name = rName;
    }

    void inputRoll(string rRoll){
        rollNumber = rRoll;
    }
    
    void inputMark(int rMarks){
        mark = rMarks;
    }

    void inputGrade(char rGrade){
        grade = rGrade;
    }

    void displayDetails() const override{
        Student::displayDetails();
        Test::displayDetails();
    }
};

int main(){
    studentPerformance tawhid;
    tawhid.inputName("MD. Tawhidul Islam");
    tawhid.inputRoll("41230201224");
    tawhid.inputMark(89);
    tawhid.inputGrade('A');
    tawhid.displayDetails();
}