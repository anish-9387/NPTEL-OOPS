#include<iostream>
using namespace std;

template<typename T1, typename T2>
class Pair{
    T1 first;
    T2 second;

public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    T1 getFirst() const{
        return first;
    }

    T2 getSecond() const{
        return second;
    }
};

int main(){
    Pair<int, double> myPair(10,20.5);
    cout<<"First: "<<myPair.getFirst()<<endl;
    cout<<"Second: "<<myPair.getSecond()<<endl;

    Pair<string, int> person("Alice",30);
    cout<<"Name: "<<person.getFirst()<<endl;
    cout<<"Age: "<<person.getSecond()<<endl;
    return 0;
}