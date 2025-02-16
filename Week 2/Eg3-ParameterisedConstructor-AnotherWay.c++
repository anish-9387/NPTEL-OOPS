#include<iostream>
using namespace std;

class Complex{
private: 
    double real, imaginary;

public:
    Complex(double r, double i){
        real=r;
        imaginary=i;
    }

    Complex add(Complex& other){
        double sumReal=real+other.real;
        double sumImaginary=imaginary+other.imaginary;
        return Complex(sumReal, sumImaginary);
    }

    void display(){
        cout<<real<<" + "<<imaginary<<"i"<<endl;
    }
};

int main(){
    double userReal, userImaginary;

    cout<<"Enter real part of complex number: ";
    cin>>userReal;
    cout<<"Enter imaginary part of complex number: ";
    cin>>userImaginary;

    Complex userComplex(userReal, userImaginary);

    Complex constructorComplex(3.5,2.0);

    Complex result=userComplex.add(constructorComplex);

    cout<<"User's complex number: ";
    userComplex.display();
    cout<<"Constructor's complex number: ";
    constructorComplex.display();

    cout<<"Sum of the two complex number: ";
    result.display();
    return 0;
}