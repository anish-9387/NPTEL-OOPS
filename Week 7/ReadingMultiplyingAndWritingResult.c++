#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int num1, num2;

    // Read 2 numbers from input1.txt
    ifstream inputFile("input1.txt");
    if(inputFile.is_open()){
        inputFile>>num1>>num2;
        cout<<"Read from the input file"<<endl;
        inputFile.close();
    }
    else{
        cerr<<"Unable to open input file"<<endl;
        return 1;
    }

    // Multiplying the numbers
    int result=num1*num2;

    // Write the result to output1.txt
    ofstream outputFile("output1.txt");
    if(outputFile.is_open()){
        outputFile<<result;
        cout<<"Result written to output file: "<<result<<endl;
        outputFile.close();
    }
    else{
        cerr<<"Unable to open output file"<<endl;
        return 1;
    }
    return 0;
}