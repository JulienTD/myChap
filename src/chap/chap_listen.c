/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_listen
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mychap.h"
#include "packet.h"

bool chap_listen(chap_t *chap)
{
    chap->fd = socket (AF_INET, SOCK_RAW, IPPROTO_RAW);
    packet_t *packet = packet_init("client hello");

    packet_configure_src(packet, "42.42.42.42", 42);
    packet_configure_dest(packet, chap->target, chap->port);
    packet_configure_ip(packet);
    packet_configure_udp(packet);
    packet_calculate_checksum(packet);
    packet_send(chap->fd, packet);

    
    return (true);
}