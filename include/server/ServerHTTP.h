#pragma once

#include <functional>
#include <socket/ListeningSocket.h>
#include <http/HttpRequest.h>
#include <http/HttpResponse.h>

#include <utils/Utils.h>

namespace mazio_http {
    using RoutesHandler = std::function<HttpResponse(HttpRequest& req)>;
    using Routes = std::unordered_map<std::string, RoutesHandler>;
    using MiddlewaresHandler = std::function<HttpResponse(HttpRequest& req, std::function<HttpResponse(HttpRequest&)> next)>;
    using Middlewares = std::vector<MiddlewaresHandler>;
    class ServerHTTP {
        private:
            Routes routes;
            Middlewares middlewares;
            ListeningSocket socket;
        public:
            ServerHTTP(const char* port);
            void addRoutes(std::string path, HttpMethods method, const RoutesHandler &handler) { routes[path + ":" + methodToString(method)] = handler; };
            void addMiddlewares(MiddlewaresHandler md) {middlewares.push_back(md);};
            void acceptConnections();
    };
}
