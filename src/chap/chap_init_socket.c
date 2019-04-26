/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_init_socket
*/

#include <string.h>
#include "mychap.h"
#include "packet.h"

#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
    struct sockaddr_in server_addr, my_addr;

    if (chap == NULL)
        return (false);
    chap->fd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if (chap->fd == -1) {
        printf("[Client] [Error] Failed to initialize the socket !\n");
        return (false);
    }
    init_socket_options(chap);
    int len = sizeof(chap->client);
    getsockname(chap->fd, (struct sockaddr *) &chap->client, &len);
    // bzero(&my_addr, sizeof(my_addr));
	char myIP[16];

    // getsockname(chap->fd, (struct sockaddr *) &my_addr, &len);
    inet_ntop(AF_INET, &chap->client.sin_addr, myIP, sizeof(myIP));
    chap->localport = ntohs(my_addr.sin_port);

    if (myIP[0] == '0') {
        chap->localip = strdup("127.0.0.1");
    } else {
        chap->localip = strdup(myIP);
    }
    return (true);
}