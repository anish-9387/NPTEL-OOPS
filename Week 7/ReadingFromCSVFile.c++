#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main(){
    ifstream csvFile("readFromCSVFile.csv");
    string line, cell;
    if(csvFile.is_open()){
        while(getline(csvFile,line)){
            stringstream lineStream(line);
            while(getline(lineStream,cell,',')){
                cout<<cell<<"\t";
            }
            cout<<endl;
        }
        csvFile.close();
    }

    else{
        cerr<<"Unable to open CSV File"<<endl;
    }

    return 0;
}