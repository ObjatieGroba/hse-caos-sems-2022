#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/epoll.h>

int main() {
    struct addrinfo hints = {.ai_family = AF_INET, .ai_socktype = SOCK_STREAM};
    struct addrinfo *res = NULL;
    getaddrinfo("hse.ru", "https", &hints, &res);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    connect(sock, res->ai_addr, res->ai_addrlen);  /// use socket as Client
    struct sockaddr_in addr = {AF_INET};
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    printf("%d\n", bind(sock, (void*)&addr, sizeof(addr)));
    listen(sock, 16);  /// User socket as server
    printf("%d\n", sock);

    struct sockaddr_in client_addr;
    socklen_t sz = sizeof(client_addr);
    int client_fd = accept(sock, (void*)&client_addr, &sz);
    printf("%d\n", client_fd);
    write(client_fd, "abacaba\n", 8);

    struct epoll_event ev;

}
