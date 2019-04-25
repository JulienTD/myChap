/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_receive
*/

#include "mychap.h"
#include "packet.h"

char *chap_receive(chap_t *chap)
{
    int packet_header_udp_size = sizeof(struct iphdr) + sizeof(struct udphdr);
    char *msg = calloc(512, sizeof(char));
    ssize_t msglen = 0;

    if (msg == NULL)
        return (false);
    // do {
        msglen = recvfrom(chap->fd, msg, 512, 0, NULL, NULL);
        if (msglen == -1)
            return (false);
        if (msglen <= packet_header_udp_size)
            return (NULL);
    // } while ((((struct udphdr *)(msg + sizeof(struct ip)))->uh_dport != chap->localport) && \
    //             ntohs(((struct udphdr *)(msg + sizeof(struct iphdr)))->dest) != chap->port);
    msg[msglen] = '\0';
    // printf("Data: %s\n", msg + sizeof(struct iphdr) + sizeof(struct udphdr));
    // printf("PORT: %d\n\n", ntohs(((struct udphdr *)(msg + sizeof(struct iphdr)))->dest));
    // if (ntohs(((struct udphdr *)(msg + sizeof(struct iphdr)))->dest) != 25567)
    //     return (chap_receive(chap));
    // struct iphdr *ip_header = (struct iphdr *)msg;

    // printf("%s\n", inet_ntoa(ip_header->saddr));
    return (msg);
}