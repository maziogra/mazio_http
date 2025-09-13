#pragma once
#include <string>
#include <unordered_map>

#include "Methods.h"

namespace mazio_http {

    class Request {
        private:
            Methods method;
            std::string path;
            std::string version;
            std::unordered_map<std::string, std::string> headers;
            std::string body;

        public:
            explicit Request(const std::string& req) {
                parseRequest(req);
            }

            Methods getMethod() const {
                return method;
            }

            std::string getPath() const {
                return path;
            }

            std::string getVersion() const {
                return version;
            }

            std::unordered_map<std::string, std::string> getHeaders() const {
                return headers;
            }

            std::string getBody() const {
                return body;
            }

            void parseRequest(const std::string& req);
    };

}
