#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ifstream file("example_cpp.txt");
    if(file){
        cout<<"File exists"<<endl;
    }
    else{
        cout<<"File does not exist"<<endl;
    }
    return 0;
}