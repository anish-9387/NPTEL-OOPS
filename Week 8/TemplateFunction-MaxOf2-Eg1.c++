#include<iostream>
using namespace std;

template <typename T>
T findMax(T a, T b){
    return (a>b) ? a : b;
}

int main(){
    cout<<"Max of 3 and 7: "<<findMax(3,7)<<endl;
    cout<<"Max of 5.5 and 2.2: "<<findMax(5.5,2.2)<<endl;
    // cout<<"Max of 3 and 2.2: "<<findMax(3,2.2)<<endl;
    return 0;
}