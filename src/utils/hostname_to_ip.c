/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** hostname_to_ip
*/

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mychap.h"
#include "packet.h"

char *hostname_to_ip(char *hostname)
{
    struct hostent *host = NULL;
    struct in_addr **addr_list = NULL;
    char *ip = NULL;

    host = gethostbyname(hostname);
    if (host == NULL)
        return (NULL);
    addr_list = (struct in_addr **)host->h_addr_list;
    if (addr_list[0] != NULL) {
        ip = strdup(inet_ntoa(*addr_list[0]));
        return (ip);
    }
    return (NULL);
}
