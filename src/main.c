/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mychap.h"
#include "packet.h"

static void printUsage()
{
    printf("./client [target] [port] [password]\n");
    printf("-t (or --target) followed by the target of ");
    printf("the remote authenticating entity.\n");
    printf("-p (or --port) followed by the port.\n");
    printf("-P (or --password) followed by the password that allows ");
    printf("you to authenticate to the entity.\n");
}

int main(int ac, char **av)
{
    chap_t *chap = NULL;

    if (ac != 7) {
        printUsage();
        return (84);
    }
    chap = chap_fill(ac, av);
    if (chap == NULL) {
        printUsage();
        return (84);
    }
    if (chap_listen(chap) == false)
        return (84);
    printf("Good job \n");
    return (0);
}