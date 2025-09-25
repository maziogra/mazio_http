#include <server/HTTPSession.h>
#include <iostream>

#include <http/HttpRequest.h>
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

        mazio_http::HttpRequest req(buffer);

        HttpResponse response = handleRequestThroughChain(req);
        const std::string res = response.toString();

        ::send(sock, res.c_str(), strlen(res.c_str()), 0);
        ::closesocket(sock);
    }

    HttpResponse HTTPSession::handleRequestThroughChain(HttpRequest& req) {
        const auto route = routes.find(req.getPath() + ":" + methodToString(req.getMethod()));

        if (route == routes.end()) {
            return HttpResponse::error(404, "<h1>NOT FOUND</h1>");
        }

        std::function<HttpResponse(HttpRequest &)> handler = route->second;

        for (auto it = middlewares.rbegin(); it != middlewares.rend(); ++it) {
            auto mw = *it;
            handler = [mw, handler] (HttpRequest& r) { return mw(r, handler); };
        }

        HttpResponse response = handler(req);

        return response;
    }
}
