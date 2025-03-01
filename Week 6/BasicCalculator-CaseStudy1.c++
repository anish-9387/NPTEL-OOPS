#include<iostream>
#include<exception>  // #include<stdexcept>
using namespace std;

double divide(int a, int b){
    if(b==0){
        throw runtime_error("Division by zero error!!");
    }

    return (double)a/b;
}

int main(){
    int x,y;
    char operation;

    try{
        cout<<"Enter first number: ";
        cin>>x;

        cout<<"Enter second number: ";
        cin>>y;

        // To handle the newline left in the buffer
        cin.ignore();  // Ignores leftover newline character

        cout<<"\nEnter the operation(+,-,*,/): ";
        cin>>operation;

        double result;

        switch(operation){
            case '+':
                result=x+y;
                break;
            case '-':
                result=x-y;
                break;
            case '*':
                result=x*y;
                break;
            case '/':
                result=divide(x,y);
                break;
            default:
                throw invalid_argument("Invalid operation!! Use +, -, * or /");
        }

        cout<<"\nResult: "<<result<<endl;
    }

    catch(const exception& e){
        // Catch any standard exception
        cerr<<"\nError: "<<e.what()<<endl;
    }

    return 0;
}