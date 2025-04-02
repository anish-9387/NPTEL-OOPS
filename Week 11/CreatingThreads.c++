#include<iostream>
#include<thread>
using namespace std;

void printNumbers(int n){
    for(int i=1; i<=n; ++i){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){ 
    thread t1(printNumbers,10);  // Start thread
    t1.join();  // Wait for thread to finish
    return 0;
}