#include<iostream>
#include<set>
// #include<iterator>
using namespace std;

int main(){
    set<int> set1={1,2,3};
    set<int> set2={4,5,6};

    insert_iterator<set<int>> inserter(set1,set1.end());
    copy(set2.begin(),set2.end(),inserter);

    for(int val : set1){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}