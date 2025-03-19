// Associative container

#include<iostream>
#include<set>
using namespace std;

int main(){
    multiset<int> duplicateNumbers={10,20,20,30};
    duplicateNumbers.insert(30);

    for(int val : duplicateNumbers){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}