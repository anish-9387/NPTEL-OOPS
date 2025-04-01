#include<iostream>
using namespace std;

class Target{   // Adapter Interface
public:
    virtual void request()=0;
};

class LegacySystem{   // Adaptee
public:
    void specificRequest(){
        cout<<"Legacy Request"<<endl;
    }
};

class Adapter : public Target{   // Adapter
    LegacySystem* adaptee;

public:
    Adapter(LegacySystem* legacy){
        adaptee=legacy;
    }

    void request() override{
        adaptee->specificRequest();
    }
};

int main(){   // Client
    LegacySystem legacy;
    Adapter adapter(&legacy);
    adapter.request();
    return 0;
}