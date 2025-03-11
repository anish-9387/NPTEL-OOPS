#include<iostream>
using namespace std;

template<typename T>
class Storage{
    T value;

public:
    Storage(T val) : value(val) {}
    T getValue() const{
        return value;
    }
};

// Specialisation for string
template<>
class Storage<string>{
    string value;

public:
    Storage(string val) : value(val) {}
    void print() const{
        cout<<"String Storage: "<<value<<endl;
    }
};

int main(){
    Storage<int> intStorage(100);
    cout<<"Integer Storage: "<<intStorage.getValue()<<endl;

    Storage<string> strStorage("Hello, World!!!");
    strStorage.print();
    return 0;
}