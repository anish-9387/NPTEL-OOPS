// Run-time polymorphism / Late binding / Dynamic Binding

#include<iostream>
using namespace std;

class P{
    int p;
    public:
        void display(){
            cout<<"Class P"<<endl;
        }
};

class Q : public P{
    int q;
    public:
        void display(){
            cout<<"Class Q"<<endl;
        }
};

int main(){
    Q q1;
    q1.display();
    return 0;
}