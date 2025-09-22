#include <memory>
#include <thread>
#include <server/ServerHTTP.h>
#include <server/HTTPSession.h>

namespace mazio_http {
    ServerHTTP::ServerHTTP(const char* port) {
        socket.create(port, AF_INET, SOCK_STREAM);
        socket.listen();
    }

    void ServerHTTP::acceptConnections() {
        while (true) {
            SOCKET n_sock = socket.accept();
            auto session = std::make_shared<mazio_http::HTTPSession>(routes, n_sock);
            std::thread t(mazio_http::HTTPSession::handleRequest, session);
            t.detach();
        }
    }
}