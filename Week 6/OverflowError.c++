#include<iostream>
#include<stdexcept>
#include<climits>
using namespace std;

int multiply(int a, int b){
    if(a>0 && b>0 && a>(INT_MAX/b)){
        throw overflow_error("Overflow detected");
    }
    return a*b;
}

int main(){
    try{
        int x=50000, y=50000;
        int result=multiply(x,y);
        cout<<"Result: "<<result<<endl;
    }
    catch(const overflow_error& e){
        cout<<"Error: "<<e.what()<<endl;
    }
    return 0;
}