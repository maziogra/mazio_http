#pragma once
#include <string>
#include <http/Methods.h>

namespace mazio_http {
    class Utils {
    public:
        static std::string methodToString(mazio_http::Methods method);
    };
}
