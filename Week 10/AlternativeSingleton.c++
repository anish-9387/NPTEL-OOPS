#include<iostream>
using namespace std;

class Singleton{
private:
    Singleton() {}

    static Singleton instance;  // Eager initialisation

public:
    static Singleton& getInstance(){
        return instance;
    }

    void showMessage(){
        cout<<"Singleton instance created eagerly!"<<endl;
    }
};

Singleton Singleton::instance;

int main(){
    Singleton& singleton=Singleton::getInstance();
    singleton.showMessage();
    return 0;
}