#include<iostream>
#include<cmath>

class Circle{
private:
    double radius;

public:
    Circle(double r):radius(r){}
    // Circle(double r){
    //     radius=r;
    // }

    double calculateArea(){
        return 3.14159265359*pow(radius,2);
    }
};

int main(){
    double radius;
    std::cout<<"Enter the radius of the circle: ";
    std::cin>>radius;

    Circle myCircle(radius);

    double area=myCircle.calculateArea();
    std::cout<<"The area of the circle with radius "<<radius<<" is: "<<area<<std::endl;

    return 0;
}