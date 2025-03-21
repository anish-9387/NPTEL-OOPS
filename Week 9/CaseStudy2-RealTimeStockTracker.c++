#include<iostream>
#include<unordered_map>
#include<iomanip>
using namespace std;

class Stock{
private:
    string symbol;
    double price;

public:
    Stock() : symbol(""), price(0.0) {}

    Stock(string sym, double pr) : symbol(sym), price(pr) {}

    string getSymbol(){
        return symbol;
    }
    double getPrice(){
        return price;
    }

    Stock& operator+=(double change){
        price+=change;
        return *this;
    }
};

unordered_map<string, Stock> stockTransfer;

void displayStocks(){
    cout<<setw(10)<<"Symbol"<<setw(10)<<"Price"<<endl;
    for(auto& pair : stockTransfer){
        cout<<setw(10)<<pair.second.getSymbol()<<setw(10)<<pair.second.getPrice()<<endl;
    }
}

int main(){
    stockTransfer["AAPL"]=Stock("AAPL",150.0);
    stockTransfer["GOOG"]=Stock("GOOG",2800.0);
    stockTransfer["MSFT"]=Stock("MSFT",299.0);

    displayStocks();

    stockTransfer["AAPL"]+=5.0;
    stockTransfer["GOOG"]+=-50.0;
    stockTransfer["MSFT"]+=10.0;

    cout<<"\nUpdated Prices: \n";
    displayStocks();
    return 0;
}