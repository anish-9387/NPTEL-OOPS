// Unorderered container use hash tables for fast access

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> numbers={10,20,30,20};
    numbers.insert(40);

    for(int val : numbers){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}