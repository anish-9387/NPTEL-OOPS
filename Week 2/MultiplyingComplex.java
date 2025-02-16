import java.util.*;
// import java.lang.*;
// import java.io.*;

class Complex{
    double real;
    double imag;

    void setValues(double r, double i){
        real=r;
        imag=i;
    }

    static Complex multiply(Complex c1, Complex c2){
        Complex result=new Complex();  // constructor(dynamically allocate memory)
        result.real=c1.real*c2.real - c1.imag*c2.imag;
        result.imag=c1.real*c2.imag + c1.imag*c2.real;

        return result;
    }

    void display(){
        if(imag>=0){
            System.out.println(real+" + "+imag+"i");
        }
        else{
            System.out.println(real+" - "+(-imag)+"i");
        }
    }
}

public class MultiplyingComplex{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        Complex c1=new Complex();
        Complex c2=new Complex();

        System.out.print("Enter real and imaginary part of first complex number: ");
        double real1=sc.nextDouble();
        double imag1=sc.nextDouble();
        c1.setValues(real1, imag1);

        System.out.print("Enter real and imaginary part of second complex number: ");
        double real2=sc.nextDouble();
        double imag2=sc.nextDouble();
        c2.setValues(real2, imag2);

        Complex result=Complex.multiply(c1, c2);

        System.out.print("Result of multiplication is: ");
        result.display();

        sc.close();
    }
}