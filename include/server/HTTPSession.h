#pragma once

#include <functional>
#include <winsock2.h>
#include <http/Response.h>

#include <http/Request.h>

#include <server/ServerHTTP.h>

namespace mazio_http {
    class HTTPSession {
        private:
            const std::unordered_map<std::string, mazio_http::RoutesHandler>& routes;
            SOCKET sock;
        public:
            HTTPSession(const std::unordered_map<std::string, mazio_http::RoutesHandler>& routes, SOCKET sock) : routes(routes), sock(sock) {}
            ~HTTPSession() = default;

            void handleRequest();
    };
}
