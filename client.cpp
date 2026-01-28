#include <iostream>
#include <winsock2.h>

int main(){

    WSADATA wsa = {0};

    

    if( WSAStartup(MAKEWORD(2, 2), &wsa) != 0){
        std::cerr << "Erreur: " << WSAGetLastError() << std::endl;
        return -1;
    }
    
    SOCKET socket;

    if((socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        std::cerr << "Erreur: " << WSAGetLastError() << std::endl;
        return -1;
    }

    struct sockaddr_in server_addr = {0};

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = INADDR_ANY;
    server_addr.sin_port = htons(25566);

    bind(socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    return 0;
}
