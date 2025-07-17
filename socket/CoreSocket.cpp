#include "CoreSocket.h"

#define _WIN32_WINNT 0x0601
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdexcept>
#include <iostream>

namespace mazio_http {
    CoreSocket::CoreSocket() {
        if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
            throw std::runtime_error("Failed to load WsaData");
        }

        if(LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
            throw std::runtime_error("Version 2.2 is not available");
        }
    }

    CoreSocket::~CoreSocket(){
        destroy();
    }

    int CoreSocket::create(const char* port, const int family, const int type) {
        struct addrinfo hints;
        struct addrinfo *res;

        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_INET; // IPv4
        hints.ai_socktype = SOCK_STREAM; // TCP
        hints.ai_flags = AI_PASSIVE;
    
        getaddrinfo(NULL, port, &hints, &res);

        for(res=res;res != NULL; res = res->ai_next) {
            sock = ::socket(res->ai_family, res->ai_socktype, res->ai_protocol);
            if(sock == INVALID_SOCKET) {
                continue;
            }

            if(bind(sock, res->ai_addr, (int)res->ai_addrlen) == SOCKET_ERROR) {
                closesocket(sock);
                sock = INVALID_SOCKET;
                continue;
            }

            std::cout << "Socket created successfully on port " << port << std::endl;
            return 1;
            break;
        }

        return 1;
    }

    void CoreSocket::destroy() {
        if(sock != INVALID_SOCKET) {
            closesocket(sock);
            sock = INVALID_SOCKET;
            std::cout << "Socket destroyed successfully" << std::endl;
        } else {
            std::cout << "No socket to destroy" << std::endl;
        }

        WSACleanup();
    }
}