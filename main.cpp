#include <server/ServerHTTP.h>

#include <iostream>

int main() {
    try {
        mazio_http::ServerHTTP server;
        server.start("8080");
        std::cout << "Server started on port 8080" << std::endl;
        server.acceptConnections();
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}