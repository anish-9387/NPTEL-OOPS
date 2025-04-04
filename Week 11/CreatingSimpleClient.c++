#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

int main(){
    int client_fd=socket(AF_INET,SOCK_STREAM,0);

    sockaddr_in server_address={0};
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(8080);
    inet_pton(AF_INET,"127.0.0.1",&server_address.sin_addr);

    connect(client_fd,(struct sockaddr*)&server_address, sizeof(server_address));
    char buffer[1024]={0};
    read(client_fd,buffer,1024);

    cout<<"Server says: "<<buffer<<endl;

    close(client_fd);
    return 0;
}