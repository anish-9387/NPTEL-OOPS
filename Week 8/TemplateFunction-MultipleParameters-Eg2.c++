#include<iostream>
using namespace std;

template<typename T1, typename T2>
T1 findMax(T1 a, T2 b){
    return (a>b) ? a : static_cast<T1>(b);
}

int main(){
    cout<<"Max of 7.8 and 4: "<<findMax(7.8,4)<<endl;
    cout<<"Max of 5.5 and 5.2: "<<findMax(5.5,5.2)<<endl;
    cout<<"Max of 5 and 5.2: "<<findMax(5,5.2)<<endl;
    cout<<"Max of 5.0 and 5.2: "<<findMax(5.0,5.2)<<endl;
    return 0;
}