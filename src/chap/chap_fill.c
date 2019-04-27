/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_fill
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "mychap.h"

static bool fill_target(chap_t *chap, int i, char **av)
{
    if (chap == NULL || av == NULL)
        return (false);
    if (hostname_to_ip(av[i + 1]) == NULL) {
        printf("No such hostname: '%s'\n", av[i + 1]);
        exit(84);
    }
    chap->target = strdup(hostname_to_ip(av[i + 1]));
    return (true);
}

static bool fill_port(chap_t *chap, int i, char **av)
{
    if (chap == NULL || av == NULL)
        return (false);
    chap->port = atoi(av[i + 1]);
    return (true);
}

static bool fill_password(chap_t *chap, int i, char **av)
{
    if (chap == NULL || av == NULL)
        return (false);
    chap->password = strdup(av[i + 1]);
    return (true);
}

static bool dispatch_args(chap_t *chap, int i, int ac, char **av)
{
    if (chap == NULL || i < 0 || i > ac || av == NULL)
        return (false);
    if (strcmp(av[i], "-t") == 0 || strcmp(av[i], "--target") == 0)
        return (fill_target(chap, i, av));
    if (strcmp(av[i], "-p") == 0 || strcmp(av[i], "--port") == 0)
        return (fill_port(chap, i, av));
    if (strcmp(av[i], "-P") == 0 || strcmp(av[i], "--password") == 0)
        return (fill_password(chap, i, av));
    return (false);
}

chap_t *chap_fill(int ac, char **av)
{
    chap_t *chap = chap_init();

    if (chap == NULL)
        return (NULL);
    for (int i = 1; i < ac; i += 2) {
        if (dispatch_args(chap, i, ac, av) == false)
            return (NULL);
    }
    return (chap);
}