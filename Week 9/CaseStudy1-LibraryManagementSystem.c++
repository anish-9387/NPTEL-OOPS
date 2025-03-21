#include<iostream>
#include<map>
using namespace std;

class Book{
private:
    int id;
    string title;

public:
    Book() : id(0), title("----") {}

    Book(int id, string title) : id(id), title(title) {}

    int getId() const{
        return id;
    }
    string getTitle() const{
        return title;
    }

    bool operator<(const Book& other) const{
        return id < other.id;
    }
    bool operator==(const Book& other) const{
        return (id==other.id && title==other.title);
    }
};

int main(){
    map<int,Book> library;

    // Adding books
    library[1]=Book(1,"C++ Primer");
    library[2]=Book(2,"Effective STL");
    library[3]=Book(3,"Clean Code");

    // Displaying library
    for(const auto& entry : library){
        cout<<"ID: "<<entry.first<<", Title: "<<entry.second.getTitle()<<endl;
    }

    // Searching a book
    int searchId=2;
    auto it=library.find(searchId);

    if(it!=library.end()){
        cout<<"Found: ID = "<<it->first<<", Title = "<<it->second.getTitle()<<endl;
    }
    else{
        cout<<"Book not found"<<endl;
    }
    return 0;
}