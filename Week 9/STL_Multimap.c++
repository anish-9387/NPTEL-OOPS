// Associative container

#include<iostream>
#include<map>
using namespace std;

int main(){
    multimap<string,int> multiAgeMap;
    multiAgeMap.insert({"Alice",25});
    multiAgeMap.insert({"Alice",28});

    for(auto pair : multiAgeMap){
        cout<<pair.first<<": "<<pair.second<<endl;
    }
    return 0;
}