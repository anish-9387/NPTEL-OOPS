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
    Q q;
    q.display();

    P p;
    p.display();
}