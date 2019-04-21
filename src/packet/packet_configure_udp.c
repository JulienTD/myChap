/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_configure_udp
*/

#include "packet.h"

// @Brief Configure the packet with udp protocol.
//        (The data must be set before this function)
bool packet_configure_udp(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    packet->udph->source = htons(packet->src_port);
    packet->udph->dest = htons(packet->dest_port);
    packet->udph->len = htons(8 + strlen(packet->data));
    packet->udph->check = 0;
    return (true);
}