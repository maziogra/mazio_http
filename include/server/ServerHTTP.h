#pragma once

#include <socket/ListeningSocket.h>

namespace mazio_http {
    class ServerHTTP {
        private:
            mazio_http::ListeningSocket socket;
        public:
            ServerHTTP() = default;
            ~ServerHTTP() = default;

            void start(const char* port);

            void acceptConnections();
    };
}