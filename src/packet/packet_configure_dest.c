/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_configure_dest
*/

#include "packet.h"
#include <stdlib.h>
#include <string.h>

bool packet_configure_dest(packet_t *packet, char *dest_addr, int dest_port)
{
    if (packet == NULL || dest_addr == NULL || dest_port < 0)
        return (false);
    packet->dest_addr = strdup(dest_addr);
    packet->dest_port = dest_port;
    return (true);
}