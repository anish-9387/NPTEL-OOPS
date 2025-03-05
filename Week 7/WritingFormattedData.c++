#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){
    ofstream myfile("formattedDataInC++.txt");
    if(myfile.is_open()){
        myfile<<fixed<<setprecision(2);
        myfile<<"Value: "<<123.456<<endl;

        myfile<<left<<setw(20)<<"Name"<<setw(10)<<"Score"<<endl;
        myfile<<left<<setw(20)<<"Alice"<<setw(10)<<95<<endl;
        myfile<<left<<setw(20)<<"Bob"<<setw(10)<<87<<endl;
        myfile<<left<<setw(20)<<"Charlie"<<setw(10)<<78<<endl;
        myfile.close();
    }
    else{
        cerr<<"Unable to open data file"<<endl;
    }
    return 0;
}