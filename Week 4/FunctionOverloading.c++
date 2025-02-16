// Static binding / Compile-time polymorphism

#include<iostream>
using namespace std;

double area(double radius){  // area of circle
    return 3.14159265358979323846*radius*radius;
}

double area(double length, double width){  // area of rectangle
    return length*width;
}

double area(double base, double height, bool isTriangle){
    return 0.5*base*height;
}

int main(){
    double radius=5.0;
    double length=10.0, width=4.0;
    double base=6.0, height=3.0;

    cout<<"Area of the circle: "<<area(radius)<<endl;
    cout<<"Area of the rectangle: "<<area(length,width)<<endl;
    cout<<"Area of the triangle: "<<area(base,height,true)<<endl;
}