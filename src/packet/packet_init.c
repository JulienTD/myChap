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

    if (packet == NULL || data == NULL)
        return (NULL);
    packet->datagram = calloc(4096, sizeof(char));
    if (packet->datagram == NULL)
        return (NULL);
    packet->iph = (struct iphdr *)packet->datagram;
    packet->udph = (struct udphdr *)(packet->datagram + sizeof(struct ip));
    packet->data = packet->datagram + sizeof(struct iphdr) + \
                    sizeof(struct udphdr);
    strcpy(packet->data, data);
    return (packet);
}