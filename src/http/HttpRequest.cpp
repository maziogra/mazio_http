#include <iostream>
#include <http/HttpRequest.h>
#include <http/HttpMethods.h>

#include <sstream>

#include "utils/Utils.h"

void mazio_http::HttpRequest::parseRequest(const std::string& req) {
    std::istringstream iss(req);
    std::string line;

    if (!std::getline(iss, line))
        throw std::runtime_error("Request vuota");

    if (!line.empty() && line.back() == '\r') line.pop_back();

    std::istringstream lineStream(line);
    std::string methodStr;

    std::string fullPath;

    lineStream >> methodStr>> fullPath >> version;

    int pos = fullPath.find('?');
    if (pos != std::string::npos) {
        path = fullPath.substr(0, pos);
        query_params = parseQueryString(fullPath.substr(pos+1));
    } else {
        path = fullPath;
    }

    if (methodStr == "GET") method = HttpMethods::GET;
    else if (methodStr == "HEAD") method = HttpMethods::HEAD;
    else if (methodStr == "POST") method = HttpMethods::POST;
    else if (methodStr == "PUT") method = HttpMethods::PUT;
    else if (methodStr == "DELETE") method = HttpMethods::DELETE_HTTP;
    else if (methodStr == "CONNECT") method = HttpMethods::CONNECT;
    else if (methodStr == "OPTIONS") method = HttpMethods::OPTIONS;
    else if (methodStr == "TRACE") method = HttpMethods::TRACE;
    else if (methodStr == "PATCH") method = HttpMethods::PATCH;
    else throw std::runtime_error("Metodo HTTP non supportato");


    while (std::getline(iss, line) && line != "\r" && !line.empty()) {
        if (line.back() == '\r') line.pop_back();
        auto pos = line.find(':');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            value.erase(0, value.find_first_not_of(" "));
            headers[key] = value;
        }
    }

    std::string bodyContent((std::istreambuf_iterator<char>(iss)),
                             std::istreambuf_iterator<char>());
    body = bodyContent;
}
