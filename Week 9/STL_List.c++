#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_front(5);

    cout<<"List after pushing elements: ";
    for(int num : numbers){
        cout<<num<<" ";
    }
    cout<<endl;

    numbers.pop_front();
    numbers.pop_back();

    cout<<"Remaining list after popping: ";
    for(int num : numbers){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}