#pragma once

#include <functional>
#include <socket/ListeningSocket.h>
#include <http/Request.h>
#include <http/Response.h>

#include <utils/Utils.h>

namespace mazio_http {
    using RoutesHandler = std::function<Response(Request req)>;
    class ServerHTTP {
        private:
            std::unordered_map<std::string, RoutesHandler> routes;
            mazio_http::ListeningSocket socket;
        public:
            ServerHTTP(const char* port);
            void addRoutes(std::string path, Methods method, const RoutesHandler &handler) { routes[path + ":" + mazio_http::Utils::methodToString(method)] = handler; };
            void acceptConnections();
    };
}
