#include<iostream>
using namespace std;

class Example{
public: 
    int a;
    
    Example(int x){  // parameterised constructor
        a=x;
    }

    Example(Example &ob){  // copy constructor
        a=ob.a;
    }
};

int main(){
    Example e1(36);  // calling parameterised constructor
    Example e2(e1);  // calling copy constructor
    cout<<e2.a<<endl;
    return 0;
}