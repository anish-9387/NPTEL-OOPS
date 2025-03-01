#include<iostream>
#include<exception>
using namespace std;

class MyException : public exception{
public:
    const char* what() const throw(){
        return "Attempted to divide by zero\n";
    }
};

int main(){
    try{
        int l,m;
        cout<<"Enter the two numbers: ";
        cin>>l>>m;

        if(m==0){
            MyException n;
            throw n;
        }
        else{
            cout<<"l/m = "<<l/m<<endl;
            cout<<"You have done 50% of OOP"<<endl;
            cout<<"All the best"<<endl;
        }
    }

    catch(exception& e){
        cout<<e.what();
    }
}