#include<iostream>
using namespace std;

class Logger{
private:
    static Logger* instance;
    Logger() {}

public:
    static Logger* getInstance(){
        if(instance==nullptr){
            instance=new Logger();
        }
        return instance;
    }

    void logMessage(const string& message){
        cout<<"Log: "<<message<<endl;
    }
};

Logger* Logger::instance=nullptr;

int main(){
    Logger* logger=Logger::getInstance();
    logger->logMessage("Singleton Logger Initialised !");
    logger->logMessage("Logging an event......");
    return 0;
}