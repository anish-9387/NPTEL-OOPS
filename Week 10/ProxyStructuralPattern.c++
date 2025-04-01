#include<iostream>
using namespace std;

class Image{  // Subject
public:
    virtual void display()=0;
};

class RealImage : public Image{  // Real Subject
    string fileName;

public:
    RealImage(string file) : fileName(file) {}

    void display(){
        cout<<"Displaying "<<fileName<<endl;
    }
};

class ProxyImage : public Image{  // Proxy
    RealImage* realImage;
    string fileName;

public:
    ProxyImage(string file) : fileName(file), realImage(nullptr) {}

    void display(){
        if(!realImage)  realImage=new RealImage(fileName);
        realImage->display();
    }
};

int main(){  // Client
    ProxyImage proxy("large_image.png");
    proxy.display();
    return 0;
}