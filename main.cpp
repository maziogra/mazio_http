#include <server/ServerHTTP.h>

#include <iostream>

mazio_http::Response test(mazio_http::Request req) {
    return mazio_http::Response::ok("IT WORKS!!!!");
}

int main() {
    try {
        mazio_http::ServerHTTP server("8080");
        std::cout << "Server started on port 8080" << std::endl;
        server.addRoutes("/test", mazio_http::Methods::GET, test);
        server.acceptConnections();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}