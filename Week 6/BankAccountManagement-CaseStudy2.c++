#include<iostream>
#include<stdexcept>
using namespace std;

class BankAccount{
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double initialBalance){
        if(initialBalance<0){
            throw invalid_argument("Initial balance cannot be negative!!");
        }
        accountHolder=name;
        balance=initialBalance;
    }

    void deposit(double amount){
        if(amount<0){
            throw invalid_argument("Deposit amount must be positive!!");
        }
        balance+=amount;
        cout<<"Deposited successfully! New balance: Rs."<<balance<<endl;
    }

    void withdraw(double amount){
        if(amount>balance){
            throw runtime_error("Insufficient funds!! Cannot withdraw that amount");
        }
        if(amount<=0){
            throw invalid_argument("Withdrawl amount must be positive!!");
        }
        balance-=amount;
        cout<<"Withdrawl successful!! New balance: Rs."<<balance<<endl;
    }

    void display(){
        cout<<"Account Holder: "<<accountHolder<<endl;
        cout<<"Current balance: Rs."<<balance<<endl;
    }
};

int main(){
    try{
        BankAccount account("Pradeep",1000.0);
        account.display();
        cout<<endl;
        
        account.deposit(500.0);
        cout<<endl;

        account.withdraw(2000.0);
    }

    // catch(const exception& e){
    //     cerr<<"Error: "<<e.what()<<endl;
    // }

    catch(const invalid_argument& e){
        cerr<<"Error: "<<e.what()<<endl;
    }

    catch(const runtime_error& e){
        cerr<<"Error: "<<e.what()<<endl;
    }
}