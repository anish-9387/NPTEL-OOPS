#include<iostream>
using namespace std;

class Employee{
public:
    Employee(){
        cout<<"Constructor Invoked"<<endl;
    }
    
    ~Employee(){
        cout<<"Destructor Invoked"<<endl;
    }
};

int main(){
    Employee e1;
    cout<<&e1<<endl;

    Employee e2;
    cout<<&e2<<endl;
    return 0;
}