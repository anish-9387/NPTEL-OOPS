// Compile time polymorphism / Early Binding / Static Binding

#include<iostream>
using namespace std;

class Cal{
public:
    static int add(int a, int b){
        return a+b;
    }

    static int add(int a, int b, int c){
        return a+b+c;
    }
};

int main(){
    Cal C;
    cout<<C.add(10,20)<<endl;
    cout<<C.add(12,20,23)<<endl;
    return 0;
}