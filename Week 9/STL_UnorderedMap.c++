// Unordered container

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> ageMap;
    ageMap["Alice"]=25;
    ageMap["Bob"]=30;

    for(auto pair : ageMap){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    return 0;
}