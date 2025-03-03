#include<iostream>
#include<fstream>  // both reading and writing
using namespace std;

int main(){
    // ofstream is in-built class and myfile is an object we have created
    ofstream myfile("example.txt");
    if(myfile.is_open()){
        myfile<<"Writing!\n";  // writing into the file
        myfile<<"Welcome to File Handling\n";
        cout<<"Written in the file successfully"<<endl;
        myfile.close();
    }
    return 0;
}