// Associative container

#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string,int> ageMap;
    ageMap["Alice"]=25;
    ageMap["Bob"]=30;

    for(const auto& pair : ageMap){   // auto pair:ageMap
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    return 0;
}