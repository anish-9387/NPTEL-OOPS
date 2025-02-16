#include<iostream>
using namespace std;

class Book{
private:
    string title;
    string author;
    double price;

public:
    // Default constructor
    Book():title("Unknown"), author("Unknown"), price(0.0){}  // ---> 1

    // Book(){
    //     title="Unknown";
    //     author="Unknown";
    //     price=0.0;
    // }   // ---> 2

    // 1 and 2 both are equivalent

    void displayBookDetails(){
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Price: Rs."<<price<<endl;
    }
};

int main(){
    Book myBook;

    cout<<"Book Details:"<<endl;
    myBook.displayBookDetails();
    return 0;
}