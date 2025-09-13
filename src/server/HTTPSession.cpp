#include <server/HTTPSession.h>
#include <iostream>

#include "http/Request.h"

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

        mazio_http::Request req(buffer);

        std::string res = "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: 11\r\n"
        "\r\n"
        "Hello World";

        ::send(sock, res.c_str(), strlen(res.c_str()), 0);

    }
}
