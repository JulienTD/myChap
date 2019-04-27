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
    char *buffer = NULL;
    int size = 0;
    int packet_port = 0;

    if (chap == NULL)
        return (NULL);
    while (1) {
        buffer = calloc(1024, sizeof(char));
        size = recvfrom(chap->fd, buffer, 1024, 0, NULL, NULL);
        buffer[size] = '\0';
        packet_port = ntohs(((struct udphdr *)(buffer + \
                            sizeof(struct iphdr)))->dest);
        if (packet_port == 17)
            return (buffer);
        free(buffer);
    }
    return (NULL);
}