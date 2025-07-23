#include <server/HTTPSession.h>

#include <iostream>

namespace mazio_http {
    void HTTPSession::handleRequest() {
        char buffer[1024];

        int received = ::recv(sock, buffer, sizeof(buffer) - 1, 0);

        if (received < 0) {
            std::cerr << "Error receiving data" << std::endl;
            return;
        } else if (received == 0) {
            std::cout << "Connection closed by client" << std::endl;
            return;
        }
    
        buffer[received] = '\0';
        std::cout << "Received request: " << buffer << std::endl;

        const char* response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
        ::send(sock, response, strlen(response), 0);

    }
}