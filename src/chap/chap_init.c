/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_init
*/

#include <stdlib.h>
#include "mychap.h"

chap_t *chap_init(void)
{
    chap_t *chap = malloc(sizeof(chap_t));

    if (chap == NULL)
        return (NULL);
    chap->password = NULL;
    chap->target = NULL;
    chap->port = 0;
    return (chap);
}