#include<iostream>
using namespace std;

template<typename T=int, typename U=double>
class DataPair{
    T first;
    U second;

public:
    DataPair(T a, U b) : first(a), second(b) {}
    T getFirst(){
        return first;
    }

    U getSecond() const{
        return second;
    }
};

int main(){
    // Default datatypes
    DataPair<> defaultPair(10,20.5);
    cout<<"First: "<<defaultPair.getFirst()<<endl;
    cout<<"Second: "<<defaultPair.getSecond()<<endl;

    // User-specified datatypes
    DataPair<char, float> customPair('A',3.14f);
    cout<<"First: "<<customPair.getFirst()<<endl;
    cout<<"Second: "<<customPair.getSecond()<<endl;
    return 0;
}