#pragma once

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <windows.h>

namespace mazio_http {
    class CoreSocket {
        private:
            WSAData wsaData;
            SOCKET sock;
        public:
            CoreSocket();
            ~CoreSocket();
            int create(const char* port, const int family, const int type);
            void destroy();
    };
}