#include<iostream>
using namespace std;

class Distance{
private:
    int meters, centimeters;

public:
    void getDistance(){
        cout<<"Enter meters: ";
        cin>>meters;
        cout<<"Enter centimeters: ";
        cin>>centimeters;
    }

    void displayDistance(){
        cout<<"Distance: "<<meters<<" meters "<<centimeters<<" centimeters "<<endl;
    }

    Distance addDistance(const Distance& d1, const Distance& d2){
        Distance result;
        result.meters=d1.meters+d2.meters;
        result.centimeters=d1.centimeters+d2.centimeters;

        if(result.centimeters>=100){
            result.meters+=result.centimeters/100;
            result.centimeters=result.centimeters%100;
        }

        return result;
    }
};

int main(){
    Distance distance1, distance2, result;

    cout<<"Enter the first distance: "<<endl;
    distance1.getDistance();
    cout<<"Enter the second distance: "<<endl;
    distance2.getDistance();

    result=result.addDistance(distance1,distance2);

    cout<<"Sum of the distances: "<<endl;
    result.displayDistance();
    return 0;
}