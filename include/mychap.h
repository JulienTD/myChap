/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** mychap
*/

#ifndef MYCHAP_H_
    #define MYCHAP_H_

#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/udp.h>
#include <netinet/ip.h>

typedef struct chap_s
{
    char *target;
    int port;
    char *password;
    int fd;
    struct sockaddr_in client;
} chap_t;

chap_t *chap_init(void);
chap_t *chap_fill(int ac, char **av);
bool chap_listen(chap_t *chap);
bool chap_send(chap_t *chap, char *data);
char *chap_receive(chap_t *chap);
bool chap_init_socket(chap_t *chap);
bool chap_destroy(chap_t *chap);
char *hostname_to_ip(char *hostname);
#endif /* !MYCHAP_H_ */
