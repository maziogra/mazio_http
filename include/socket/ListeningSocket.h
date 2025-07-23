#pragma once

#include <socket/CoreSocket.h>

namespace mazio_http {
    class ListeningSocket : public CoreSocket {
        private:
            static const int MAX_CON = 5;
        public:
            ListeningSocket(const char* port, const int family, const int type);
            ListeningSocket() = default;
            int listen(int backlog = MAX_CON);
            SOCKET accept();
    };
}