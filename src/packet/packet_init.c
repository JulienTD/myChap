/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_init
*/

#include "packet.h"

packet_t *packet_init(char *data)
{
    packet_t *packet = malloc(sizeof(packet_t));

    if (packet == NULL)
        return (NULL);
    memset(packet->datagram, 0, 4096);
    packet->iph = (struct iphdr *) packet->datagram;
    packet->udph = (struct udphdr *) (packet->datagram + \
                    sizeof(struct ip));
    packet->data = packet->datagram + sizeof(struct iphdr) + \
                    sizeof(struct udphdr);
    strcpy(packet->data, data);
    return (packet);
}