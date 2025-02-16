#include<iostream>
using namespace std;

class Employee{
public:
    int id;
    string name;
    float salary;

    Employee(int i, string n, float s){   // Parameterised Constructor
        id=i;
        name=n;
        salary=s;
    }

    void display(){
        cout<<id<<"  "<<name<<"  "<<salary<<endl;
    }
};

int main(){
    Employee e1=Employee(7,"MS Dhoni",100000);
    Employee e2=Employee(45,"Rohit Sharma",80000);
    e1.display();
    e2.display();
    return 0;
}