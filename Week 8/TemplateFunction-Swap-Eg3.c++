#include<iostream>
using namespace std;

template <typename T>
void swapValue(T& a, T& b){
    T temp=a;
    a=b;
    b=temp;
}

int main(){
    int x=10, y=20;
    cout<<"Before swap: x= "<<x<<", y= "<<y<<endl;
    swapValue(x,y);
    cout<<"After swap: x= "<<x<<", y= "<<y<<endl;

    double p=5.5, q=9.9;
    cout<<"Before swap: p= "<<p<<", q= "<<q<<endl;
    swapValue(p,q);
    cout<<"After swap: p= "<<p<<", q= "<<q<<endl;
    return 0;
}