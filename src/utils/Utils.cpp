#include <utils/Utils.h>

namespace mazio_http {
    std::string Utils::methodToString(mazio_http::Methods method) {
        switch(method) {
            case mazio_http::Methods::GET:          return "GET";
            case mazio_http::Methods::HEAD:         return "HEAD";
            case mazio_http::Methods::POST:         return "POST";
            case mazio_http::Methods::PUT:          return "PUT";
            case mazio_http::Methods::DELETE_HTTP:  return "DELETE";
            case mazio_http::Methods::CONNECT:      return "CONNECT";
            case mazio_http::Methods::OPTIONS:      return "OPTIONS";
            case mazio_http::Methods::TRACE:        return "TRACE";
            case mazio_http::Methods::PATCH:        return "PATCH";
            default:                                return "UNKNOWN";
        }
    }
}
