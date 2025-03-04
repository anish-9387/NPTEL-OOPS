#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream myfile("example3.txt");
    if(myfile.is_open()){
        myfile<<"Line 1"<<endl;
        myfile<<"Line 2"<<endl;
        myfile<<"Line 3"<<endl;
        myfile.close();
    }
    return 0;
}