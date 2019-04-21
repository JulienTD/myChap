/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** mychap
*/

#ifndef MYCHAP_H_
    #define MYCHAP_H_

#include <stdbool.h>

typedef struct chap_s
{
    char *target;
    int port;
    char *password;
    int fd;
} chap_t;

chap_t *chap_init(void);
chap_t *chap_fill(int ac, char **av);
bool chap_listen(chap_t *chap);

#endif /* !MYCHAP_H_ */
