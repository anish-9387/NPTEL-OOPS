#include<iostream>
using namespace std;

class Box{
private:
    int length;

public:
    Box() : length(0){}

    friend int printLength(Box);
};

int printLength(Box b){
    b.length+=10;
    return b.length;
}

int main(){
    Box b;
    cout<<"Length of the box: "<<printLength(b)<<endl;
    return 0;
}