#include <server/ServerHTTP.h>

#include <iostream>

mazio_http::HttpResponse test(mazio_http::HttpRequest req) {
    std::cout << *req.getQueryParam("name");
    return mazio_http::HttpResponse::ok("hello");
}

int main() {
    try {
        mazio_http::ServerHTTP server("8080");
        std::cout << "Server started on port 8080" << std::endl;
        server.addRoutes("/test", mazio_http::HttpMethods::GET, test);
        server.acceptConnections();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}