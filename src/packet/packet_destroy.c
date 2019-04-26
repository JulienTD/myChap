/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_destroy
*/

#include "packet.h"

bool packet_destroy(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    if (packet->datagram)
        free(packet->datagram);
    // if (packet->src_addr)
    //     free(packet->src_addr);
    if (packet->dest_addr)
        free(packet->dest_addr);
    if (packet->pseudogram)
        free(packet->pseudogram);
    free(packet);
    return (true);
}