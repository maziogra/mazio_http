#pragma once

#include <functional>
#include <winsock2.h>
#include <http/Response.h>

#include <http/Request.h>

#include <server/ServerHTTP.h>

namespace mazio_http {
    class HTTPSession {
        private:
            const Routes& routes;
            const Middlewares& middlewares;
            SOCKET sock;
            Response handleRequestThroughChain(Request& req);
        public:
            HTTPSession(const Routes& routes, const Middlewares& middlewares, SOCKET sock) : routes(routes), middlewares(middlewares), sock(sock) {}
            ~HTTPSession() = default;

            void handleRequest();
    };
}
