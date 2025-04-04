#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
using namespace std;

int main(){
    int server_fd=socket(AF_INET,SOCK_STREAM,0);  // AF_INET --> IPv4, SOCK_STREAM --> TCP Socket

    sockaddr_in address={0};
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=INADDR_ANY;
    address.sin_port=htons(8080);

    bind(server_fd,(struct sockaddr*)&address, sizeof(address));
    listen(server_fd,3);  // 3--> allowance to 3 pending client connection

    cout<<"Server listening on port 8080"<<endl;
    int client_socket=accept(server_fd,nullptr,nullptr);  // (address , length)
    send(client_socket,"Hello, Client!",14,0);  // 14--> length of string, 0--> no special flags is used

    close(client_socket);
    close(server_fd);
    return 0;
}