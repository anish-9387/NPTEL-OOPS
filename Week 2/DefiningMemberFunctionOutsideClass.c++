#include<iostream>
using namespace std;

class MyClass{
public: 
    void printMessage();
};

void MyClass::printMessage(){  // defined outside class
    cout<<"Hello from MyClass!!!"<<endl;
}

int main(){
    MyClass myObj;
    myObj.printMessage();
    return 0;
}