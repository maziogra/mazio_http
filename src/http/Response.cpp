#include <http/Response.h>
#include <sstream>

namespace mazio_http {
    std::string Response::defaultResponseContentType = "text/html";

    Response Response::ok(std::string message) {
        Response r = Response(200, message, "HTTP/1.1");
        r.addHeader("Content-Type", defaultResponseContentType);
        r.addHeader("Content-Length", std::to_string(r.body.size()));
        return r;
    }

    Response mazio_http::Response::error(int statusCode, std::string message) {
        Response r = Response(statusCode, message, "HTTP/1.1");
        r.addHeader("Content-Type", defaultResponseContentType);
        r.addHeader("Content-Length", std::to_string(r.body.size()));
        return r;
    }

    std::string Response::toString() {
        std::ostringstream response;

        response << version << " " << statusCode << "\r\n";

        for (const auto& [key, value] : headers) {
            response << key << ": " << value << "\r\n";
        }

        response << "\r\n";

        response << body;

        return response.str();
    }
}