#include<iostream>
using namespace std;

class Box{
protected:
    double width;
};

class SmallBox : Box{
public:
    void setSmallWidth(double wid);
    double getSmallWidth();
};

void SmallBox::setSmallWidth(double wid){
    width=wid;
}

double SmallBox::getSmallWidth(){
    return width;
}

int main(){
    SmallBox box;

    box.setSmallWidth(7.0);
    cout<<"Width of box: "<<box.getSmallWidth()<<endl;
    return 0;
}