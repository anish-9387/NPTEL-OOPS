// Synchronisation in C++

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex mtx;

void printNumbers(int id){
    lock_guard<mutex> lock(mtx);  // RAII for lock
    for(int i=1; i<=5; ++i){
        cout<<"Thread "<<id<<": "<<i<<endl;
    }
}

int main(){
    thread t1(printNumbers,1);
    thread t2(printNumbers,2);
    t1.join();
    t2.join();
    return 0;
}