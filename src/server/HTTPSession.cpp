#include <server/HTTPSession.h>
#include <iostream>

#include <http/Request.h>
#include <utils/Utils.h>

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

        auto lambda = routes.find(req.getPath() + ":" + mazio_http::Utils::methodToString(req.getMethod()));
        std::string res;

        if (lambda != routes.end()) {
            res = (lambda->second(req)).toString();
        } else {
            res = "HTTP/1.1 200 OK\r\n"
                    "Content-Type: text/html\r\n"
                    "Content-Length: 18\r\n"
                    "\r\n"
                    "<h1>Not Found</h1>";
        }

        ::send(sock, res.c_str(), strlen(res.c_str()), 0);

    }
}
