#include<iostream>
using namespace std;

class Employee{
public:
    Employee(){   // default constructor
        cout<<"Testing Default Constructor"<<endl;
    }
};

int main(){
    Employee e1;
    Employee e2;
    return 0;
}