#pragma once
#include <optional>
#include <string>
#include <unordered_map>

#include <http/HttpMethods.h>

namespace mazio_http {

    class HttpRequest {
        private:
            HttpMethods method;
            std::string path;
            std::string version;
            std::unordered_map<std::string, std::string> headers;
            std::unordered_map<std::string, std::string> query_params;
            std::string body;

        public:
            explicit HttpRequest(const std::string& req) {
                parseRequest(req);
            }

            HttpMethods getMethod() const {
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

            std::optional<std::string> getHeader(const std::string& key) const {
                auto it = headers.find(key);
                if (it != headers.end())
                    return it->second;
                return std::nullopt;
            }

            std::optional<std::string> getQueryParam(const std::string& key) const {
                auto it = query_params.find(key);
                if (it != query_params.end())
                    return it->second;
                return std::nullopt;
            }

            std::unordered_map<std::string, std::string> getQueryParams() const {
                return query_params;
            }

            std::string getBody() const {
                return body;
            }

            void setMethod(HttpMethods method) {
                this->method = method;
            }

            void setPath(std::string path) {
                this->path = path;
            }

            void setVersion(std::string version) {
                this->version = version;
            }

            void setHeaders(std::unordered_map<std::string, std::string> headers) {
                this->headers = headers;
            }

            void setQueryParams(std::unordered_map<std::string, std::string> query_params) {
                this->query_params = query_params;
            }

            void setBody(std::string body) {
                this->body = body;
            }

            void addHeader(const std::string& key, const std::string& value) {
                headers[key] = value;
            }

            void removeHeader(const std::string& key) {
                headers.erase(key);
            }

            void addQueryParam(const std::string& key, const std::string& value) {
                query_params[key] = value;
            }

            void removeQueryParam(const std::string& key) {
                query_params.erase(key);
            }

            void parseRequest(const std::string& req);
    };

}
