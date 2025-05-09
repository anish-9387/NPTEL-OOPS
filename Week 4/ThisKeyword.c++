// Resolving variable shadowing

#include<iostream>
using namespace std;

class Employee{
public:
    int id;
    string name;
    float salary;

    Employee(int id, string name, float salary){
        this->id=id;
        this->name=name;
        this->salary=salary;
    }

    void display(){
        cout<<id<<"  "<<name<<"  "<<salary<<endl;
    }
};

int main(){
    Employee e1=Employee(7,"MSD",100000);
    Employee e2=Employee(45,"Rohit",50000);
    e1.display();
    e2.display();
    return 0;
}