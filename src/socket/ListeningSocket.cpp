#include "ListeningSocket.h"

#define _WIN32_WINNT 0x0601
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdexcept>
#include <iostream>

namespace mazio_http {

    ListeningSocket::ListeningSocket(const char* port, const int family, const int type) {
        if(create(port, family, type) != 1) {
            throw std::runtime_error("Failed to create ListeningSocket");
        }
    }

    int ListeningSocket::listen(int backlog) {
        if(::listen(getSocket(), backlog) == SOCKET_ERROR) {
            std::cerr << "Failed to listen on socket" << std::endl;
            return -1;
        }

        std::cout << "Listening, waiting for connections..." << std::endl;

        return 0;
    }

    SOCKET ListeningSocket::accept() {
        SOCKET new_sock;
        struct sockaddr_storage addr;
        socklen_t addr_size;
        
        addr_size = sizeof(addr);
        new_sock = ::accept(getSocket(), (struct sockaddr*)&addr, &addr_size);

        if(new_sock == INVALID_SOCKET) {
            std::cerr << "Failed to accept connection" << std::endl;
            return INVALID_SOCKET;
        }

        return new_sock;
    }
}