/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_calculate_checksum
*/

#include "packet.h"

static unsigned short csum(unsigned short *ptr,int nbytes)
{
    register long sum;
    unsigned short oddbyte;
    register short answer;

    sum=0;
    while (nbytes>1) {
        sum += *ptr++;
        nbytes -= 2;
    }
    if (nbytes == 1) {
        oddbyte = 0;
        *((u_char*)&oddbyte) = *(u_char*)ptr;
        sum += oddbyte;
    }
    sum = (sum>>16) + (sum & 0xffff);
    sum = sum + (sum>>16);
    answer=(short)~sum;
    return(answer);
}

// @Brief Configure the packet with udp protocol.
//        (The data must be set before this function)
bool packet_calculate_checksum(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    packet->psh.source_address = packet->iph->saddr;//inet_addr( source_ip );
    packet->psh.dest_address = packet->sin.sin_addr.s_addr;
    packet->psh.placeholder = 0;
    packet->psh.protocol = IPPROTO_UDP;
    packet->psh.udp_length = htons(sizeof(struct udphdr) + strlen(packet->data) );
    
    int psize = sizeof(struct pseudo_header) + sizeof(struct udphdr) + strlen(packet->data);
    packet->pseudogram = malloc(psize);
    
    memcpy(packet->pseudogram , (char*) &packet->psh , sizeof (struct pseudo_header));
    memcpy(packet->pseudogram + sizeof(struct pseudo_header), packet->udph, sizeof(struct udphdr) + strlen(packet->data));
    
    packet->udph->check = csum( (unsigned short*) packet->pseudogram , psize);
    
    return (true);
}