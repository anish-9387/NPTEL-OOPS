#include<iostream>
using namespace std;

template<typename T>
class Storage{
    T value;

public:
    Storage(T val){
        value=val;
    }

    T getValue() const{
        return value;
    }
};

int main(){
    Storage<int> intStorage(100);
    Storage<double> doubleStorage(99.99);

    cout<<"Integer Storage: "<<intStorage.getValue()<<endl;
    cout<<"Double Storage: "<<doubleStorage.getValue()<<endl;
    return 0;
}