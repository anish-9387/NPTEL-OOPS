#include<iostream>
#include<thread>
// #include<semaphore>
using namespace std;

// counting_semaphore<3> semaphore{3};  // Capacity of 3

void worker(int id){
    // semaphore.acquire();
    cout<<"Worker "<<id<<" is running"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    // semaphore.release();
}

int main(){
    thread t1(worker,1), t2(worker,2), t3(worker,3), t4(worker,4);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}