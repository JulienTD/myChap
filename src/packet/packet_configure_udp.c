/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_configure_udp
*/

#include "packet.h"

bool packet_configure_udp(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    packet->udph->source = packet->client.sin_port;
    packet->udph->dest = packet->server.sin_port;
    packet->udph->len = htons(8 + strlen(packet->data));
    packet->udph->check = 0;
    return (true);
}