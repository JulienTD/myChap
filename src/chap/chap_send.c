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
    if (packet_configure_src(packet, "127.0.0.1", 25567) == false)
        return (false);
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
    return (true);
}