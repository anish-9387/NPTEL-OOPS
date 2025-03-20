#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> numbers={10,20,30,40,20,50,20};

    auto it=find(numbers.begin(),numbers.end(),30);
    if(it!=numbers.end()){
        cout<<"Found: "<<*it<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    int c=count(numbers.begin(),numbers.end(),20);
    cout<<"Count of 20: "<<c<<endl;
    return 0;
}