/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_init
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "mychap.h"
#include "packet.h"

chap_t *chap_init(void)
{
    chap_t *chap = malloc(sizeof(chap_t));

    if (chap == NULL)
        return (NULL);
    chap->password = NULL;
    chap->target = NULL;
    chap->port = 0;
    chap->fd = -1;
    return (chap);
}