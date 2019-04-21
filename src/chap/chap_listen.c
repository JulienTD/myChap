/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** chap_listen
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include "mychap.h"
#include "packet.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <openssl/sha.h>

static char *sha256(const char *str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH] = {0};
    SHA256_CTX sha256;
    char *output_buffer;

    if (!(output_buffer = calloc(1, \
                            sizeof(char) * ((SHA256_DIGEST_LENGTH * 2) + 1))))
        return (NULL);
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(output_buffer + (i * 2), "%02x", hash[i]);
    output_buffer[64] = 0;
    return (output_buffer);
}


bool chap_listen(chap_t *chap)
{
    char *curr_data = NULL;
    char *final_password = NULL;

    if (chap_init_socket(chap) == false)
        return (false);
    if (chap_send(chap, "client hello") == false) {
        printf("No such hostname: '%s'\n", chap->target);
        return (false);
    }
    for (char *data = chap_receive(chap); data != NULL; data = chap_receive(chap)) {
        if (strlen(data + sizeof(struct iphdr) + sizeof(struct udphdr)) != 10)
            continue;
        curr_data = data;
        break;
    }
    final_password = calloc(strlen(chap->password) + 11, sizeof(char));
    final_password = strcat(final_password, (curr_data + sizeof(struct iphdr) + sizeof(struct udphdr)));
    final_password = strcat(final_password, chap->password);
    chap_send(chap, sha256(final_password));
    char *data = chap_receive(chap);
    data = chap_receive(chap);
    if (strcmp(data + sizeof(struct iphdr) + sizeof(struct udphdr), "KO") == 0) {
        printf("KO\n");
        return (true);
    }
    printf("Secret: '%s'\n", data + sizeof(struct iphdr) + sizeof(struct udphdr));
    return (true);
}
