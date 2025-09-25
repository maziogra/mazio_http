#pragma once

#include <functional>
#include <winsock2.h>
#include <http/HttpResponse.h>

#include <http/HttpRequest.h>

#include <server/ServerHTTP.h>

namespace mazio_http {
    class HTTPSession {
        private:
            const Routes& routes;
            const Middlewares& middlewares;
            SOCKET sock;
            HttpResponse handleRequestThroughChain(HttpRequest& req);
        public:
            HTTPSession(const Routes& routes, const Middlewares& middlewares, SOCKET sock) : routes(routes), middlewares(middlewares), sock(sock) {}
            ~HTTPSession() = default;

            void handleRequest();
    };
}
