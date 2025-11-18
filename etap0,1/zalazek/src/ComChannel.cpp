#include "ComChannel.hh"
#include "Port.hh" 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

ComChannel::~ComChannel() {
if (_socket != -1) {
Disconnect();
}
}

bool ComChannel::Connect(const std::string& host, int port) {
    sockaddr_in server_addr;
    bzero((char *)&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host.c_str());
    server_addr.sin_port = htons(port);

    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket < 0) {
        std::cerr << "*** Blad otwarcia gniazda." << std::endl;
        return false;
    }

    if (connect(_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "*** Brak mozliwosci polaczenia do portu: " << port << std::endl;
        close(_socket);
        _socket = -1;
        return false;
    }

    std::cout << "Polaczono z serwerem graficznym na porcie " << port << std::endl;
        return true;
}

void ComChannel::Disconnect() {
    if (_socket != -1) {
    std::cout << "Zamykanie polaczenia z serwerem." << std::endl;
    Send("Close\n");
    close(_socket);
    _socket = -1;
    }
}


bool ComChannel::Send(const std::string& msg) const {
    if (_socket == -1) {
        std::cerr << "*** Blad: Proba wyslania danych bez aktywnego polaczenia." << std::endl;
        return false;
    }

    ssize_t bytes_sent;
    ssize_t total_to_send = msg.length();

    const char* msg_ptr = msg.c_str();

    while (total_to_send > 0 && (bytes_sent = write(_socket, msg_ptr, total_to_send)) > 0) {
        total_to_send -= bytes_sent;
        msg_ptr += bytes_sent;
    }

    if (bytes_sent < 0) {
        std::cerr << "*** Blad podczas przesylania danych." << std::endl;
        return false;
    }
    return true;
}