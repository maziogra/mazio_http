#include "socket/CoreSocket.h"

#include <iostream>

int main() {
    try {
        mazio_http::CoreSocket coreSocket;
        coreSocket.create("8080", AF_INET, SOCK_STREAM);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}