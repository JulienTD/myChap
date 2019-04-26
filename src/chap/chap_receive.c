/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_receive
*/

#include "mychap.h"
#include "packet.h"

static bool is_resp_packet(char *buffer, chap_t *chap)
{
    int packet_port =
    ntohs(((struct udphdr *)(buffer + sizeof(struct iphdr)))->dest);
    // printf("Dest: %d    Port: %d    Data: %s\n", packet_port, chap->localport, buffer + sizeof(struct iphdr) + sizeof(struct udphdr));
    if (packet_port == 17)//chap->localport)
        return true;
    return false;
}

char *chap_receive(chap_t *chap)
{
    char *buffer;
    int size;

    for (int i = 0; i >= 0; i++) {
        buffer = calloc(1024, sizeof(char));
        size = recvfrom(chap->fd, buffer, 1024, 0,
        NULL, NULL);
        buffer[size] = '\0';
        if (is_resp_packet(buffer, chap))
            return buffer;
        free(buffer);
    }
    return NULL;
    // int packet_header_udp_size = sizeof(struct iphdr) + sizeof(struct udphdr);
    // ssize_t msglen = 0;
    // char *msg = NULL;

    // do {
    //     msg = calloc(512, sizeof(char));
    //     if (msg == NULL)
    //         return (false);
    //     msglen = recvfrom(chap->fd, msg, 512, 0, NULL, NULL);
    //     if (msglen == -1)
    //         return (false);
    //     if (msglen <= packet_header_udp_size) {
    //         free(msg);
    //         continue;
    //     }
    //     msg[msglen] = '\0';
    //     printf("Port: %ld\n", ntohs(((struct udphdr *)(msg + sizeof(struct iphdr)))->dest));
    // } while (ntohs(((struct udphdr *)(msg + sizeof(struct iphdr)))->dest) != 25567);
    // printf("Data: %s\n", msg + sizeof(struct iphdr) + sizeof(struct udphdr));
    // printf("PORT: %d\n\n", ntohs(((struct udphdr *)(msg + sizeof(struct iphdr)))->dest));
    // if (ntohs(((struct udphdr *)(msg + sizeof(struct iphdr)))->dest) != 25567)
    //     return (chap_receive(chap));
    // struct iphdr *ip_header = (struct iphdr *)msg;

    // printf("%s\n", inet_ntoa(ip_header->saddr));
    // return (msg);
}