#include<iostream>
using namespace std;

class Shape{
public:
    virtual void draw()=0;
};

class Circle : public Shape{
public:
    void draw() override{
        cout<<"Drawing circle"<<endl;
    }
};

class Square : public Shape{
public:
    void draw() override{
        cout<<"Drawing square"<<endl;
    }
};

class ShapeFactory{
public:
    static Shape* createShape(const string& type){
        if(type=="circle")  return new Circle();
        if(type=="square")  return new Square();
        return nullptr;
    }
};

int main(){
    Shape* shape=ShapeFactory::createShape("circle");
    
    if(shape)  shape->draw();
    delete shape;
    return 0;
}