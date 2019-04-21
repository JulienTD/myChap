/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_init_socket
*/

#include "mychap.h"
#include "packet.h"

static bool init_socket_options(chap_t *chap)
{
    int can_be_reused = 1;
    int on = 1;

    if (setsockopt(chap->fd, SOL_SOCKET, SO_REUSEADDR, \
        &can_be_reused, sizeof(int)) == -1) {
        printf("[Client] [Warning] Failed to set the socket options (Reuse addr)!\n");
    }
    if (setsockopt(chap->fd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1) {
        printf("[Client] [Warning] Failed to set the socket options (HDRINCL)!\n");
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
    socklen = (socklen_t) sizeof(chap->addr);
    if (bind(chap->fd, (struct sockaddr*) &chap->addr, socklen) == -1) {
        printf("[Client] [Error] Failed to bind the socket !\n");
        return (false);
    }
    return (true);
}