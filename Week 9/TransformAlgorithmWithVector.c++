#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> numbers={1,2,3,4,5};
    vector<int> squared(numbers.size());

    transform(numbers.begin(),numbers.end(),squared.begin(),[](int x){
        return x*x;
    });

    for(int val : squared){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}