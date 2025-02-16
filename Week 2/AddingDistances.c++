#include<iostream>
using namespace std;

class Distance{
    int feet, inches;

public:
    void setValues(int f, int i){
        feet=f;
        inches=i;
    }

    Distance add(Distance d){
        Distance result;
        result.inches=inches+d.inches;

        result.feet=feet+d.feet+(result.inches/12);
        result.inches%=12;
        return result;
    }

    void display(){
        cout<<feet<<" feet and "<<inches<<" inches"<<endl;
    }
};

int main(){
    Distance d1, d2, result;
    int feet1, inches1, feet2, inches2;

    cout<<"Enter feet and inches for the 1st distance: ";
    cin>>feet1>>inches1;
    d1.setValues(feet1,inches1);

    cout<<"Enter feet and inches for the 2nd distance: ";
    cin>>feet2>>inches2;
    d2.setValues(feet2,inches2);

    result=d1.add(d2);   // new type of calling function in class

    cout<<"The sum of the two distances is: ";
    result.display();
    return 0;
}