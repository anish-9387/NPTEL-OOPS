#include<iostream>
using namespace std;

class Test{
public:
    string testString;

    void setData(string testString){
        this->testString=testString;
    }

    void getAndPrint(string str){
        this->setData(str);
        cout<<"The string is: "<<this->testString<<endl;
    }
};

int main(){
    Test test;
    test.getAndPrint("This is a test for member accession!");
    return 0;
}