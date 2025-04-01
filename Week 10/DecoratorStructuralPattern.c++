#include<iostream>
using namespace std;

class UIComponent{  // Base Component Interface
public:
    virtual ~UIComponent()=default;
    virtual string render() const=0;
};

class Window : public UIComponent{  // Concrete Component: A Basic Window
public:
    string render() const override{
        return "Window";
    }
};

class Decorator : public UIComponent{  // Abstract Decorator class
protected:
    UIComponent* component;

public:
    Decorator(UIComponent* comp){
        component=comp;
    }

    virtual ~Decorator(){
        delete component;
    }

    string render() const override{
        return component->render();
    }
};

class ScrollbarDecorator : public Decorator{  // Concrete Decorator: Adds scrollbar
public:
    ScrollbarDecorator(UIComponent* comp) : Decorator(comp) {}

    string render() const override{
        return component->render() + " with Scrollbar";
    }
};

class BorderDecorator : public Decorator{  // Concrete decorator: Adds border
public:
    BorderDecorator(UIComponent* comp) : Decorator(comp) {}

    string render() const override{
        return component->render() + " with Border";
    }
};

int main(){
    UIComponent* simpleWindow=new Window();

    UIComponent* windowWithScrollbar=new ScrollbarDecorator(simpleWindow);

    UIComponent* decoratedWindow=new BorderDecorator(windowWithScrollbar);

    cout<<decoratedWindow->render()<<endl;

    delete decoratedWindow;
    return 0;
}