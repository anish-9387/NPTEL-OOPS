#include<iostream>
#include<vector>
using namespace std;

class Observer{
public:
    virtual void update(const string& message)=0;
};

class ConcreteObserver : public Observer{
public:
    void update(const string& message) override{
        cout<<"Observer recieved: "<<message<<endl;
    }
};

class Subject{
    vector<Observer*> observers;

public:
    void attach(Observer* observer){
        observers.push_back(observer);
    }

    void notify(const string& message){
        for(auto observer : observers){
            observer->update(message);
        }
    }
};

int main(){
    Subject subject;
    ConcreteObserver observer1, observer2;

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.notify("Hello Observers!!!");
    return 0;
}