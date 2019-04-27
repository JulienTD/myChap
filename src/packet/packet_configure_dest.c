/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_configure_dest
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include "packet.h"

bool packet_configure_dest(packet_t *packet, char *dest_addr, int dest_port)
{
    if (packet == NULL || dest_addr == NULL || dest_port < 0)
        return (false);
    packet->dest_addr = strdup(dest_addr);
    packet->dest_port = dest_port;
    packet->server.sin_port = htons(dest_port);
    packet->server.sin_addr.s_addr = inet_addr(dest_addr);
    packet->server.sin_family = AF_INET;
    return (true);
}