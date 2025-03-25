#include<iostream>
using namespace std;

class Counter{
private:
    static Counter* instance;
    int count;

    Counter() : count(0) {}

public:
    static Counter* getInstance(){
        if(instance==nullptr){
            instance=new Counter();
        }
        return instance;
    }

    void increment(){
        count++;
    }

    int getCount(){
        return count;
    }
};

Counter* Counter::instance=nullptr;

int main(){
    Counter* counter=Counter::getInstance();
    counter->increment();
    counter->increment();
    cout<<"Count: "<<counter->getCount()<<endl;
    return 0;
}