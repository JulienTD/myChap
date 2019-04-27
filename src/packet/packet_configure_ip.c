/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_configure_ip
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/limits.h>
#include "packet.h"

bool packet_configure_ip(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    packet->iph->ihl = 5;
    packet->iph->version = 4;
    packet->iph->tos = 0;
    packet->iph->tot_len = sizeof(struct iphdr) + \
                            sizeof(struct udphdr) + strlen(packet->data);
    packet->iph->id = htonl(54321);
    packet->iph->frag_off = 0;
    packet->iph->ttl = 255;
    packet->iph->protocol = IPPROTO_UDP;
    packet->iph->check = 0;
    packet->iph->saddr = packet->client.sin_addr.s_addr;
    packet->iph->daddr = packet->server.sin_addr.s_addr;
    packet->iph->check = 0;
    return (true);
}