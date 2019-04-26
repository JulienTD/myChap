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
    packet->udph->source = packet->client.sin_port;//htons(packet->src_port);
    packet->udph->dest = packet->server.sin_port;//htons(packet->dest_port);
    packet->udph->len = htons(8 + strlen(packet->data));
    packet->udph->check = 0;
    return (true);
}