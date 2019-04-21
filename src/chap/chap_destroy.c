/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_destroy
*/

#include <stdlib.h>
#include <unistd.h>
#include "mychap.h"

bool chap_destroy(chap_t *chap)
{
    if (chap == NULL)
        return (false);
    if (chap->fd != -1)
        close(chap->fd);
    if (chap->password)
        free(chap->password);
    if (chap->target)
        free(chap->target);
    free(chap);
    return (true);
}