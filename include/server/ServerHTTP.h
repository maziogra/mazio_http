#pragma once

#include <functional>
#include <socket/ListeningSocket.h>
#include <http/Request.h>
#include <http/Response.h>

#include <utils/Utils.h>

namespace mazio_http {
    using RoutesHandler = std::function<Response(Request& req)>;
    using Routes = std::unordered_map<std::string, RoutesHandler>;
    using MiddlewaresHandler = std::function<Response(Request& req, std::function<Response(Request&)> next)>;
    using Middlewares = std::vector<MiddlewaresHandler>;
    class ServerHTTP {
        private:
            Routes routes;
            Middlewares middlewares;
            ListeningSocket socket;
        public:
            ServerHTTP(const char* port);
            void addRoutes(std::string path, Methods method, const RoutesHandler &handler) { routes[path + ":" + Utils::methodToString(method)] = handler; };
            void addMiddlewares(MiddlewaresHandler md) {middlewares.push_back(md);};
            void acceptConnections();
    };
}
