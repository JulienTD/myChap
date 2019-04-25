/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_init_socket
*/

#include <string.h>
#include "mychap.h"
#include "packet.h"

static bool init_socket_options(chap_t *chap)
{
    int can_be_reused = 1;
    int on = 1;

    if (setsockopt(chap->fd, SOL_SOCKET, SO_REUSEADDR, \
        &can_be_reused, sizeof(int)) == -1) {
        printf("[Client] [Warning] Failed to set the socket options ");
        printf("Reuse addr)!\n");
    }
    if (setsockopt(chap->fd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1) {
        printf("[Client] [Warning] Failed to set the socket options ");
        printf("HDRINCL)!\n");
    }
    return (true);
}

bool chap_init_socket(chap_t *chap)
{
    socklen_t socklen = 0;

    if (chap == NULL)
        return (false);
    chap->fd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if (chap->fd == -1) {
        printf("[Client] [Error] Failed to initialize the socket !\n");
        return (false);
    }
    init_socket_options(chap);

    // socklen_t socklen = sizeof(chap->sin);
    // struct sockaddr_in server_addr;
    // bzero(&server_addr, sizeof(server_addr));
    // server_addr.sin_family = AF_INET;
    // server_addr.sin_addr.s_addr = inet_addr(chap->target);
    // server_addr.sin_port = htons(chap->port);

    // // Connect to server
    // if (connect(chap->fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    //     perror("Connect server error");
    //     // close(sockfd);
    //     exit(-1);
    // }
    // char myIP[16];
    // getsockname(chap->fd, (struct sockaddr *)&chap->addr, &socklen);
    // inet_ntop(AF_INET, &chap->addr, myIP, sizeof(myIP));
    // int myPort = ntohs(chap->addr.sin_port);

    // chap->localip = strdup(myIP);
    // printf("Local ip address: %s\n", myIP);
    // printf("Local port : %u\n", myPort);
    // socklen = (socklen_t)sizeof(chap->addr);
    // if (bind(chap->fd, (struct sockaddr *)&chap->addr, socklen) == -1) {
    //     printf("[Client] [Error] Failed to bind the socket !\n");
    //     return (false);
    // }
    return (true);
}