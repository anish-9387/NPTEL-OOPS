#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // Opening file for reading char-by-char
    ifstream myfile("example.txt");
    cout<<"Reading character by character:\n";
    char c;
    if(myfile.is_open()){
        while(myfile.get(c)){
            if(c=='\n'){
                cout<<"\\n";
            }
            else if(c==' '){
                cout<<"_";
            }
            else{
                cout<<c;
            }
        }
        myfile.close();
    }

    // Opening file for reading line-by-line
    cout<<"\n\nReading line by line:\n";
    myfile.open("example.txt");
    if(myfile.is_open()){
        string line;
        int lineNumber=1;
        while(getline(myfile,line)){
            cout<<"Line "<<lineNumber++<<": "<<line<<endl;
        }
        myfile.close();
    }

    return 0;
}