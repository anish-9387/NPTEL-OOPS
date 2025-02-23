#include<iostream>
using namespace std;

class Students{
private:
    string name;
    int rollNumber;
    char grade;

public:
    Students(string studentName, int studentRoll, char studentGrade){
        name=studentName;
        rollNumber=studentRoll;
        setGrade(studentGrade);
    }

    string getName() const{
        return name;
    }

    void setName(string studentName){
        name=studentName;
    }

    int getRollNumber() const{
        return rollNumber;
    }

    void setRollNumber(int studentRoll){
        rollNumber=studentRoll;
    }

    char getGrade() const{
        return grade;
    }

    void setGrade(char studentGrade){
        if(studentGrade>='A' && studentGrade<='F'){
            grade=studentGrade;
        }
        else{
            cout<<"Invalid grade! Grade must be between A and F"<<endl;
        }
    }

    void displayStudentDetails() const{
        cout<<"Student name: "<<name<<endl;
        cout<<"Roll number: "<<rollNumber<<endl;
        cout<<"Grade: "<<grade<<endl;
    }
};

int main(){
    Students s1("Manasvi",101,'A');

    s1.displayStudentDetails();
    cout<<endl;

    s1.setName("Himanshi");
    s1.setGrade('B');

    cout<<"Updated Student Details: "<<endl;
    s1.displayStudentDetails();
    cout<<endl;

    s1.setGrade('Z');
    return 0;
}