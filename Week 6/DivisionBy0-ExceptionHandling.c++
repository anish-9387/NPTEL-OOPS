#include<iostream>
using namespace std;

double division(int a, int b){
    if(b==0){
        throw "Division by zero condition";
    }
    return (a/b);
}

int main(){
    int l=1729, m=0;
    double n=0;

    try{
        n=division(l,m);
        cout<<n<<endl;
    }
    
    catch(const char* msg){
        cerr<<msg<<endl;
    }
    return 0;
}