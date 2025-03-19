// Sequence container

// Deque ==> Double ended queue is a dynamic array that supports efficient insertion and deletion at both ends

#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> numbers;

    numbers.push_back(10);
    numbers.push_front(5);
    numbers.push_back(15);

    for(int val : numbers){
        cout<<val<<" ";
    }
    cout<<endl;

    numbers.pop_front();
    numbers.pop_back();

    for(int val : numbers){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}