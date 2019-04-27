/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_send
*/

#include "mychap.h"
#include "packet.h"

bool chap_send(chap_t *chap, char *data)
{
    packet_t *packet = packet_init(data);

    if (packet == NULL)
        return (false);
    packet->client = chap->client;
    if (packet_configure_dest(packet, chap->target, chap->port) == false)
        return (false);
    if (packet_configure_ip(packet) == false)
        return (false);
    if (packet_configure_udp(packet) == false)
        return (false);
    if (packet_calculate_checksum(packet) == false)
        return (false);
    if (packet_send(chap->fd, packet) == false)
        return (false);
    packet_destroy(packet);
    return (true);
}