#include<iostream>
using namespace std;

class Employee{
private:
    int id;
    string name;
    int age;
    double salary;

public:
    Employee(){   // default constructor
        id=0;
        name="Unknown";
        age=18;
        salary=0.0;
        cout<<"Default constructor called for employee with ID: "<<id<<endl;
    }

    Employee(int empID, string empName, int empAge, double empSalary){  // parameterised constructor
        id=empID;
        name=empName;
        age=empAge;
        salary=empSalary;
        cout<<"Parameterised constructor called for employee with ID: "<<id<<endl;
    }

    void displayDetails() const{
        cout<<"Employee ID: "<<id<<endl;
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee Age: "<<age<<endl;
        cout<<"Employee Salary: "<<salary<<endl;
    }

    void updateSalary(double newSalary){
        salary=newSalary;
        cout<<"Salary updated for employee with ID: "<<id<<" to "<<salary<<endl;
    }
};

int main(){
    Employee emp1;
    emp1.displayDetails();

    emp1.updateSalary(30000);
    emp1.displayDetails();
    cout<<endl;

    Employee emp2(7,"MS Dhoni",44,400000);
    emp2.displayDetails();

    emp2.updateSalary(800000);
    emp2.displayDetails();

    return 0;
}