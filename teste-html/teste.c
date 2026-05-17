#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char *html = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n"
                 "<html><body><h1>Olá do servidor em C!</h1></body></html>";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Servidor rodando em http://localhost:8080\n");

    while(1) {
        client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        write(client_socket, html, strlen(html));
        close(client_socket);
    }

    return 0;
}
