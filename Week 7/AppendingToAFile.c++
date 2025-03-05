#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream myfile;
    myfile.open("example.txt", ios::app);  // append mode

    if(myfile.is_open()){
        myfile<<"Appended line\n";
        myfile<<"New Appended line\n";
        cout<<"Appended successfully"<<endl;
        myfile.close();
    }
    return 0;
}