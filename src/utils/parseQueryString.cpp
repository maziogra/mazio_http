#include <string>
#include <unordered_map>
#include <iostream>

namespace mazio_http {
    std::unordered_map<std::string, std::string> parseQueryString(const std::string& url) {
        std::unordered_map<std::string, std::string> result;

        if (url.empty()) return result;

        std::string key;
        std::string value;
        bool ok = true;

        for (auto i = url.begin(); i != url.end(); ++i) {
            char c = *i;

            if (c == '=') {
                ok = false;
            } else if (c == '&') {
                if (!key.empty()) result[key] = value;

                key.clear();
                value.clear();
                ok = true;
            } else {
                if (ok) key.push_back(c);
                else value.push_back(c);
            }
        }

        if (!key.empty()) {
            result[key] = value;
        }

        return result;
    }
}
