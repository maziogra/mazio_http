#include <server/ServerHTTP.h>
#include <server/HTTPSession.h>

namespace mazio_http {
    void ServerHTTP::start(const char* port) {
        socket.create(port, AF_INET, SOCK_STREAM);
        socket.listen();
    }

    void ServerHTTP::acceptConnections() {
        while (true) {
            SOCKET n_sock = socket.accept();
            mazio_http::HTTPSession session(n_sock);
            session.handleRequest();

        }
    }
}