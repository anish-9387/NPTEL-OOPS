#include<iostream>
using namespace std;

class Coffee{
public:
    virtual void prepare()=0;
};

class Espresso : public Coffee{
public:
    void prepare() override{
        cout<<"Preparing Espresso"<<endl;
    }
};

class Cappuccino : public Coffee{
public:
    void prepare() override{
        cout<<"Preparing Cappuccino"<<endl;
    }
};

class CoffeeFactory{
public:
    static Coffee* createCoffee(const string& type){
        if(type=="espresso")  return new Espresso();
        if(type=="cappuccino")  return new Cappuccino();
        return nullptr;
    }
};

int main(){
    Coffee* coffee=CoffeeFactory::createCoffee("espresso");

    if(coffee)  coffee->prepare();
    delete coffee;
    return 0;
}