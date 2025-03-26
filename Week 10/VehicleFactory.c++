#include<iostream>
using namespace std;

class Vehicle{
public:
    virtual void type()=0;
};

class Car : public Vehicle{
public:
    void type() override{
        cout<<"Car created"<<endl;
    }
};

class Bike : public Vehicle{
public:
    void type() override{
        cout<<"Bike created"<<endl;
    }
};

class VehicleFactory{
public:
    static Vehicle* createVehicle(const string& type){
        if(type=="car")  return new Car();
        if(type=="bike")  return new Bike();
        return nullptr;
    }
};

int main(){
    Vehicle* vehicle=VehicleFactory::createVehicle("car");
    if(vehicle)  vehicle->type();
    delete vehicle;

    vehicle=VehicleFactory::createVehicle("bike");
    if(vehicle)  vehicle->type();
    delete vehicle;

    return 0;
}