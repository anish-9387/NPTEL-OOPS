#include<iostream>
using namespace std;

class Singleton{
private:
    static Singleton* instance;

    Singleton() {}  // private constructor

public:
    static Singleton* getInstance(){
        if(instance==nullptr){
            instance=new Singleton();
        }
        return instance;
    }

    void displayMessage(){
        cout<<"Singleton instance!"<<endl;
    }
};

// Initialising the static member
Singleton* Singleton::instance=nullptr;

int main(){
    Singleton* singleton=Singleton::getInstance();
    singleton->displayMessage();
    return 0;
}