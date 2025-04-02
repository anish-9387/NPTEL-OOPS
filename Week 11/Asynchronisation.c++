#include<iostream>
#include<future>
using namespace std;

int computeSquare(int x){
    return x*x;
}

int main(){
    future<int> result=async(launch::async,computeSquare,5);
    cout<<"Square: "<<result.get()<<endl;  // Blocks until task completes
    return 0;
}