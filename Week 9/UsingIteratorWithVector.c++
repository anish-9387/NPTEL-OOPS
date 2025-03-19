#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> numbers={10,20,30};
    vector<int>::iterator it;
    
    for(it=numbers.begin(); it!=numbers.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}