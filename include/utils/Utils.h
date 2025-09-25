#pragma once
#include <string>
#include <http/HttpMethods.h>

namespace mazio_http {
    std::string methodToString(mazio_http::HttpMethods method);
    std::unordered_map<std::string, std::string> parseQueryString(const std::string& url);
}
