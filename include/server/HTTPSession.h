#pragma once

#include <winsock2.h>

namespace mazio_http {
    class HTTPSession {
        private:
            SOCKET sock;
        public:
            HTTPSession(SOCKET sock) : sock(sock) {}
            ~HTTPSession() = default;

            void handleRequest();
    };
}