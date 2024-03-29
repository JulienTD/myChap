/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_send
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "packet.h"

bool packet_send(int fd, packet_t *packet)
{
    if (sendto(fd, packet->datagram, packet->iph->tot_len, \
                0, (struct sockaddr *)&packet->server, \
                sizeof(packet->server)) < 0) {
        return (false);
    }
    return (true);
}