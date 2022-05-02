#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_ADDR "192.168.0.211"
#define PORT 54400
#define BUFFER_SIZE 1024
#define SAFECALL(CMD, ERR)  \
    if (CMD) {              \
        perror(ERR);        \
        exit(EXIT_FAILURE); \
    }

int main(int argc, char** argv) {
    int sockfd;
    struct sockaddr_in addr;

    SAFECALL((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0, "create socket")
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    SAFECALL(inet_pton(AF_INET, SERVER_ADDR, &addr.sin_addr) <= 0, "inet_pton")
    SAFECALL(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0, "connect")

    char send_buf[BUFFER_SIZE];
    char recv_buf[BUFFER_SIZE];
    char* disconnect = "disconnect";
    for (int i = 1; i < argc; ++i) {
        printf("%s\n", argv[i]);
        strncpy(send_buf, argv[i], strlen(argv[i]));
        send(sockfd, send_buf, strlen(send_buf), 0);
        read(sockfd, recv_buf, 1024);
        if (strncmp(send_buf, recv_buf, strlen(send_buf)) != 0) {
            perror("don't match\n");
        }
    }

    // disconnect from server
    strncpy(send_buf, disconnect, strlen(disconnect));
    printf("%s\n", send_buf);
    send(sockfd, send_buf, strlen(send_buf), 0);
    read(sockfd, recv_buf, 1024);
    if (strncmp(send_buf, recv_buf, strlen(send_buf)) != 0) {
        perror("don't match\n");
    }

    return 0;
}
