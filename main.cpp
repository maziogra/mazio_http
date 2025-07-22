#include <ListeningSocket.h>

#include <iostream>

int main() {
    try {
        mazio_http::ListeningSocket listeningSocket;
        listeningSocket.create("8080", AF_INET, SOCK_STREAM);
        listeningSocket.listen();
        listeningSocket.accept();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}