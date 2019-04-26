/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_configure_src
*/

#include "packet.h"
#include <stdlib.h>
#include <string.h>

bool packet_configure_src(packet_t *packet, chap_t *chap, char *src_addr, int src_port)
{
    // if (packet == NULL || src_addr == NULL || src_port < 0)
    //     return (false);
    // packet->src_addr = strdup(src_addr);
    // packet->src_port = src_port;
    // packet->client.sin_port = htons(src_port);
    // packet->client.sin_addr.s_addr = inet_addr(src_addr);
    // packet->client.sin_family = AF_INET;

    // // bzero(&packet->client, sizeof(packet->client));
    // socklen_t len = sizeof(packet->client);
	// // char myIP[16];

    // getsockname(chap->fd, (struct sockaddr *) &packet->client, &len);
    // // inet_ntop(AF_INET, &packet->client.sin_addr, myIP, sizeof(myIP));
    // // chap->localport = ntohs(packet->client.sin_port);

    // // if (myIP[0] == '0') {
    // //     chap->localip = strdup("127.0.0.1");
    // // } else {
    // //     chap->localip = strdup(myIP);
    // // }
    return (true);
}