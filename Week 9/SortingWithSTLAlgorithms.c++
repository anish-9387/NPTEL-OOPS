#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> numbers={40,10,30,20,50};

    // Sorting in ascending order
    sort(numbers.begin(),numbers.end());
    cout<<"Ascending order: ";
    for(int val : numbers){
        cout<<val<<" ";
    }
    cout<<endl;

    // Sorting in descending order using lambda function
    sort(numbers.begin(),numbers.end(),[](int a, int b){
        return a>b;
    });
        
    cout<<"Descending order: ";
    for(int val : numbers){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}