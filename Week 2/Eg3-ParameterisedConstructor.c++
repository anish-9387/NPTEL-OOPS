#include<iostream>
using namespace std;

class Complex{
private:
    double real, imaginary;

public:
    Complex(double r, double i){  // parameterised constructor
        real=r;
        imaginary=i;
    }

    Complex add(Complex c1, Complex c2){
        double sumReal=c1.real+c2.real;
        double sumImaginary=c1.imaginary+c2.imaginary;
        return Complex(sumReal, sumImaginary);
    }

    void display(){
        cout<<real<<" + "<<imaginary<<"i"<<endl;
    }
};

int main(){
    double userReal, userImaginary;

    cout<<"Enter a complex number(real part): ";
    cin>>userReal;
    cout<<"Enter a complex number(imaginary part): ";
    cin>>userImaginary;

    Complex userComplex(userReal, userImaginary);

    Complex constructorComplex(3.5,2.0);

    Complex result=result.add(userComplex, constructorComplex);

    cout<<"User's Complex number: ";
    userComplex.display();

    cout<<"Complex number from constructor: ";
    constructorComplex.display();

    cout<<"Sum of complex numbers: ";
    result.display();
    
    return 0;
}