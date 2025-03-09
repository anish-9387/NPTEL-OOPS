#include<iostream>
#include<fstream>
using namespace std;

class MyClass{
public:
    int data;
    MyClass(int d) : data(d) {}

    // Serialise method to save data to file
    void serialise(const string& filename){
        ofstream ofs(filename, ios::binary);
        if(ofs.is_open()){
            ofs.write(reinterpret_cast<char*>(&data), sizeof(data));
            ofs.close();
            cout<<"Data serialised to "<<filename<<endl;
        }
        else{
            cerr<<"Error: Could not open file for serialisation"<<endl;
        }
    }

    // Deserialise method to load data from file
    void deserialise(const string& filename){
        ifstream ifs(filename, ios::binary);
        if(ifs.is_open()){
            ifs.read(reinterpret_cast<char*>(&data), sizeof(data));
            ifs.close();
            cout<<"Data deserialised from "<<filename<<endl;
        }
        else{
            cerr<<"Error: Could not open file for deserialsation"<<endl;
        }
    }
};

int main(){
    MyClass obj(42);
    string filename="serialised_data.bin";

    cout<<"Original data: "<<obj.data<<endl;
    obj.serialise(filename);
    cout<<"Data after serialisation: "<<obj.data<<endl;

    obj.data=0;
    cout<<"Data after reset: "<<obj.data<<endl;

    obj.deserialise(filename);
    cout<<"Data after deserialisation: "<<obj.data<<endl;
    return 0;
}