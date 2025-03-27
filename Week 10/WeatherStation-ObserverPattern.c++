#include<iostream>
#include<vector>
using namespace std;

class Observer{
public:
    virtual void update(float temperature, float humidity)=0;
};

class PhoneDisplay : public Observer{
public:
    void update(float temperature, float humidity) override{
        cout<<"Phone Display - Temp: "<<temperature<<" degree Celsius, HUmidity: "<<humidity<<"%\n";
    }
};

class WeatherStation{
    vector<Observer*> observers;
    float temperature, humidity;

public:
    void attach(Observer* observer){
        observers.push_back(observer);
    }

    void setMeasurements(float temp, float hum){
        temperature=temp;
        humidity=hum;
        notify();
    }

    void notify(){
        for(auto observer : observers){
            observer->update(temperature,humidity);
        }
    }
};

int main(){
    WeatherStation station;
    PhoneDisplay phone;

    station.attach(&phone);
    station.setMeasurements(25.0,60.0);
    station.setMeasurements(30.0,55.0);
    return 0;
}