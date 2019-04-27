/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet
*/

#ifndef PACKET_H_
    #define PACKET_H_

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/udp.h>
#include <netinet/ip.h>
#include <stdbool.h>
#include "mychap.h"

struct pseudo_header
{
    u_int32_t source_address;
    u_int32_t dest_address;
    u_int8_t placeholder;
    u_int8_t protocol;
    u_int16_t udp_length;
};

typedef struct packet_s
{
    char *datagram;
    char *data;
    char *pseudogram;
    struct iphdr *iph;
    struct udphdr *udph;
    struct sockaddr_in server;
    struct sockaddr_in client;
    struct pseudo_header psh;
    char *dest_addr;
    int dest_port;
} packet_t;

bool packet_configure_udp(packet_t *packet);
packet_t *packet_init(char *data);
bool packet_configure_dest(packet_t *packet, char *dest_addr, int dest_port);
bool packet_send(int fd, packet_t *packet);
bool packet_calculate_checksum(packet_t *packet);
bool packet_configure_ip(packet_t *packet);
bool packet_destroy(packet_t *packet);

#endif /* !PACKET_H_ */
