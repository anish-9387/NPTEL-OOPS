// Associative container

#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> uniqueNumbers={10,20,30,20};
    uniqueNumbers.insert(40);

    for(int val : uniqueNumbers){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}