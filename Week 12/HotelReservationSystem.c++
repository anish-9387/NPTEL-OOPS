#include<iostream>
#include<vector>
#include<fstream>
#include<memory>
using namespace std;

class Room{
protected:
    int roomNumber;
    bool isAvailable;

public:
    Room(int number):roomNumber(number), isAvailable(true) {}

    virtual ~Room() {}

    virtual double calculateRate(int nights)=0;

    bool checkAvailability() const{
        return isAvailable;
    }

    void bookRoom(){
        isAvailable=false;
    }

    void freeRoom(){
        isAvailable=true;
    }

    int getRoomNumber() const{
        return roomNumber;
    }
};

class StandardRoom : public Room{
public:
    StandardRoom(int number) : Room(number) {}

    double calculateRate(int nights) override{
        return 100.0*nights;
    }
};

class DeluxeRoom : public Room{
public:
    DeluxeRoom(int number) : Room(number) {}

    double calculateRate(int nights) override{
        return 150.0*nights;
    }
};

class SuiteRoom : public Room{
public:
    SuiteRoom(int number) : Room(number) {}

    double calculateRate(int nights) override{
        return 250.0*nights;
    }
};

class Customer{
    string name, phone;

public:
    Customer(string customerName, string customerPhone) : name(customerName), phone(customerPhone) {}

    string getName() const{
        return name;
    }

    string getPhone() const{
        return phone;
    }
};

class Reservation{
    shared_ptr<Room> room;
    Customer customer;
    int nights;

public:
    Reservation(shared_ptr<Room> room, const Customer& customer, int nights) : room(room), customer(customer), nights(nights){
        if(nights<=0){
            throw invalid_argument("Nights must be greater than zero");
        }
        if(!room->checkAvailability()){
            throw runtime_error("Room is not available");
        }
        room->bookRoom();
    }

    ~Reservation(){
        room->freeRoom();
    }

    double calculateTotalCost() const{
        return room->calculateRate(nights);
    }

    string getCustomerName() const{
        return customer.getName();
    }

    int getRoomNumber() const{
        return room->getRoomNumber();
    }

    void cancelReservation(){
        room->freeRoom();
        cout<<"Reservation cancelled for room "<<room->getRoomNumber()<<endl;
    }

    bool getCancellationStatus(){
        return room->checkAvailability();
    }
};

class ReservationManager{
    vector<shared_ptr<Reservation>> reservations;

public:
    void addReservation(shared_ptr<Reservation> reservation){
        reservations.push_back(reservation);
    }

    void saveAllReservations(string filename) const{
        ofstream file(filename);
        if(!file){
            throw runtime_error("Unable to open file for writing");
        }
        for(auto reservation : reservations){
            file<<reservation->getCustomerName()<<", "<<reservation->getRoomNumber()<<", "<<reservation->calculateTotalCost();
            if(reservation->getCancellationStatus()){
                file<<" (Cancelled)";
            }
            file<<"\n";
        }
        file.close();
    }

    void generateAllBills() const{
        for(auto reservation : reservations){
            if(!reservation->getCancellationStatus()){
                cout<<"Customer: "<<reservation->getCustomerName()<<endl;
                cout<<"Room: "<<reservation->getRoomNumber()<<endl;
                cout<<"Total cost: $ "<<reservation->calculateTotalCost()<<endl;
                cout<<"------------------------------------------------------"<<endl;
            }
        }
    }
};

void runTestCases(){
    try{
        cout<<"\n=== Running Test Cases ===\n";

        Customer customer1("Alice","111-222-3333");
        shared_ptr<Room> room1=make_shared<StandardRoom>(101);
        Reservation reservation1(room1,customer1,2);
        cout<<"Test 1 Passed: Standard Room booked successfully"<<endl;

        try{
            Reservation reservationInvalid(room1,customer1,-3);
        }
        catch(const invalid_argument& e){
            cout<<"Test 2 Passed: Caught invalid argument: "<<e.what()<<endl;
        }

        try{
            Reservation reservationUnavailable(room1,customer1,1);
        }
        catch(const runtime_error& e){
            cout<<"Test 3 Passed: Caught runtime error: "<<e.what()<<endl;
        }

        Customer customer2("Bob","444-555-6666");
        shared_ptr<Room> room2=make_shared<SuiteRoom>(201);
        Reservation reservation2(room2,customer2,3);
        double expectedCost=3*250.0;
        if(reservation2.calculateTotalCost()==expectedCost){
            cout<<"Test 4 Passed: Billing is correct"<<endl;
        }

        ReservationManager manager;
        manager.addReservation(make_shared<Reservation>(room2,customer2,3));
        manager.saveAllReservations("reservations_test.txt");
        cout<<"Test 5 Passed: File handling works correctly"<<endl;
    }
    catch(const exception& e){
        cerr<<"Test Failed: "<<e.what()<<endl;
    }
}

int main(){
    try{
        runTestCases();

        ReservationManager manager;

        Customer liveCustomer1("John Doe","123-456-7890");
        shared_ptr<Room> liveRoom1=make_shared<SuiteRoom>(301);
        shared_ptr<Reservation> liveReservation1=make_shared<Reservation>(liveRoom1,liveCustomer1,4);
        manager.addReservation(liveReservation1);

        Customer liveCustomer2("Jane Smith","987-654-3210");
        shared_ptr<Room> liveRoom2=make_shared<DeluxeRoom>(302);
        shared_ptr<Reservation> liveReservation2=make_shared<Reservation>(liveRoom2,liveCustomer2,2);
        manager.addReservation(liveReservation2);

        manager.generateAllBills();

        manager.saveAllReservations("reservations.txt");

        cout<<"\nCancelling reservation for room 301\n";
        liveReservation1->cancelReservation();

        manager.saveAllReservations("reservations.txt");

        try{
            shared_ptr<Reservation> newReservation=make_shared<Reservation>(liveRoom1,liveCustomer2,2);
            manager.addReservation(newReservation);
            cout<<"New reservation for room 301 created after cancellation"<<endl;
        }
        catch(const exception& e){
            cerr<<"Error: "<<e.what()<<endl;
        }

        manager.saveAllReservations("reservations.txt");
    }
    catch(const exception& e){
        cerr<<"Error: "<<e.what()<<endl;
    }
    return 0;
}