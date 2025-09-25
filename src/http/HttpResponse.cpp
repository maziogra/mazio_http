#include <http/HttpResponse.h>
#include <sstream>

namespace mazio_http {
    std::string HttpResponse::defaultResponseContentType = "text/html";

    HttpResponse HttpResponse::ok(std::string message) {
        HttpResponse r = HttpResponse(200, message, "HTTP/1.1");
        r.addHeader("Content-Type", defaultResponseContentType);
        r.addHeader("Content-Length", std::to_string(r.body.size()));
        return r;
    }

    HttpResponse mazio_http::HttpResponse::error(int statusCode, std::string message) {
        HttpResponse r = HttpResponse(statusCode, message, "HTTP/1.1");
        r.addHeader("Content-Type", defaultResponseContentType);
        r.addHeader("Content-Length", std::to_string(r.body.size()));
        return r;
    }

    std::string HttpResponse::toString() {
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