#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    for(int i=0; i<numbers.size(); i++){
        cout<<"Elements at index "<<i<<": "<<numbers.at(i)<<endl;
    }

    numbers.pop_back();
    cout<<"After pop_back, size: "<<numbers.size()<<endl;
    return 0;
}