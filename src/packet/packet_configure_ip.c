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

static unsigned short csum(unsigned short *ptr, int nbytes)
{
    long sum = 0;
    unsigned short oddbyte = 0;
    short answer = 0;

    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }
    if (nbytes == 1) {
        oddbyte = 0;
        *((u_char*)&oddbyte) = *(u_char*)ptr;
        sum += oddbyte;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum = sum + (sum >> 16);
    answer = (short)~sum;
    return (answer);
}

// @Brief Configure the packet with ip protocol.
//        (The data must be set before this function)
bool packet_configure_ip(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    packet->iph->ihl = 5;
    packet->iph->version = 4;
    packet->iph->tos = 0;
    packet->iph->tot_len = sizeof (struct iphdr) + \
                            sizeof (struct udphdr) + strlen(packet->data);
    packet->iph->id = htonl(54321); // TODO: Generate an id
    packet->iph->frag_off = 0;
    packet->iph->ttl = 255;
    packet->iph->protocol = IPPROTO_UDP;
    packet->iph->check = 0;
    packet->sin.sin_family = AF_INET;
    packet->sin.sin_port = htons(packet->dest_port);
    packet->sin.sin_addr.s_addr = inet_addr(packet->dest_addr);
    packet->iph->saddr = inet_addr(packet->src_addr);
    packet->iph->daddr = packet->sin.sin_addr.s_addr;
    packet->iph->check = csum((unsigned short *)packet->datagram, \
                        packet->iph->tot_len);
    return (true);
}