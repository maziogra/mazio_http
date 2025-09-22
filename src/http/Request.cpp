#include <iostream>
#include <http/Request.h>

#include <sstream>

void mazio_http::Request::parseRequest(const std::string& req) {
    std::istringstream iss(req);
    std::string line;

    if (!std::getline(iss, line))
        throw std::runtime_error("Request vuota");

    if (!line.empty() && line.back() == '\r') line.pop_back();

    std::istringstream lineStream(line);
    std::string methodStr;

    lineStream >> methodStr >> path >> version;

    if (methodStr == "GET") method = Methods::GET;
    else if (methodStr == "HEAD") method = Methods::HEAD;
    else if (methodStr == "POST") method = Methods::POST;
    else if (methodStr == "PUT") method = Methods::PUT;
    else if (methodStr == "DELETE") method = Methods::DELETE_HTTP;
    else if (methodStr == "CONNECT") method = Methods::CONNECT;
    else if (methodStr == "OPTIONS") method = Methods::OPTIONS;
    else if (methodStr == "TRACE") method = Methods::TRACE;
    else if (methodStr == "PATCH") method = Methods::PATCH;
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
