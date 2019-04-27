/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_init
*/

#include "packet.h"

static bool init_packet_variables(packet_t *packet)
{
    packet->datagram = NULL;
    packet->data = NULL;
    packet->pseudogram = NULL;
    packet->iph = NULL;
    packet->udph = NULL;
    packet->dest_addr = NULL;
    packet->dest_port = 0;
    return (true);
}

packet_t *packet_init(char *data)
{
    packet_t *packet = malloc(sizeof(packet_t));

    if (packet == NULL || data == NULL)
        return (NULL);
    init_packet_variables(packet);
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