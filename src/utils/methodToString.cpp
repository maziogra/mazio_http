#include <string>
#include <http/HttpMethods.h>

namespace mazio_http {
    std::string methodToString(const mazio_http::HttpMethods method) {
        switch(method) {
            case mazio_http::HttpMethods::GET:          return "GET";
            case mazio_http::HttpMethods::HEAD:         return "HEAD";
            case mazio_http::HttpMethods::POST:         return "POST";
            case mazio_http::HttpMethods::PUT:          return "PUT";
            case mazio_http::HttpMethods::DELETE_HTTP:  return "DELETE";
            case mazio_http::HttpMethods::CONNECT:      return "CONNECT";
            case mazio_http::HttpMethods::OPTIONS:      return "OPTIONS";
            case mazio_http::HttpMethods::TRACE:        return "TRACE";
            case mazio_http::HttpMethods::PATCH:        return "PATCH";
            default:                                    return "UNKNOWN";
        }
    }
}
