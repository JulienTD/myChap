/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_configure_src
*/

#include "packet.h"
#include <stdlib.h>
#include <string.h>

bool packet_configure_src(packet_t *packet, char *src_addr, int src_port)
{
    if (packet == NULL || src_addr == NULL || src_port < 0)
        return (false);
    packet->src_addr = strdup(src_addr);
    packet->src_port = src_port;
    return (true);
}