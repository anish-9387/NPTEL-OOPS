#include<iostream>
using namespace std;

class Student{
public:
    int id;
    string name;

    void insert(int i, string n){
        id=i;
        name=n;
    }

    void display(){
        cout<<id<<"  "<<name<<endl;
    }
};

int main(){
    Student s1, s2;
    s1.insert(45,"Rohit Sharma");
    s2.insert(7,"MS Dhoni");
    s1.display();
    s2.display();
    return 0;
}