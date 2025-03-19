#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> numbers={10,20,30};

    list<int>::reverse_iterator rit;
    for(rit=numbers.rbegin(); rit!=numbers.rend(); ++rit){
        cout<<*rit<<" ";
    }
    cout<<endl;
    return 0;
}