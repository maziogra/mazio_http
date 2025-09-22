#pragma once
#include <string>
#include <unordered_map>

#include "Methods.h"

namespace mazio_http {

    class Response {
        private:
          int statusCode;
          std::string version;
          std::string body;
          static std::string defaultResponseContentType;
          std::unordered_map<std::string, std::string> headers;
        public:
          Response(int statusCode, std::string body, std::string version) : statusCode(statusCode), body(body), version(version) {};
          Response(int statusCode, std::string body) : statusCode(statusCode), body(body), version("HTTP/1.1") {};
          Response(int status_code) : statusCode(status_code), body(""), version("HTTP/1.1") {};

          Response static ok(std::string message = "");
          Response static error(int statusCode, std::string message = "");

          void static setdefaultResponseContentType(std::string contentType) { defaultResponseContentType = contentType; };

          void addHeader(std::string key, std::string value) { headers[key] = value; };
          int getStatusCode() const { return statusCode; };
          std::string getVersion() const { return version; };
          std::string getbody() const { return body; };
          std::string getHeader(const std::string &key) { return headers[key]; };
          std::string toString();
    };
}
