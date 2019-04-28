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

    output_buffer = calloc(1, \
                            sizeof(char) * ((SHA256_DIGEST_LENGTH * 2) + 1));
    if (output_buffer == NULL)
        return (NULL);
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(output_buffer + (i * 2), "%02x", hash[i]);
    output_buffer[64] = 0;
    return (output_buffer);
}

static char *concat_password(chap_t *chap, char *serv_pass)
{
    char *final_password = NULL;

    final_password = calloc(strlen(chap->password) + 11, sizeof(char));
    if (final_password == NULL)
        return (NULL);
    final_password = strcat(final_password, serv_pass);
    final_password = strcat(final_password, chap->password);
    return (final_password);
}

bool chap_listen(chap_t *chap)
{
    char *curr_data = NULL;

    if (chap_init_socket(chap) == false)
        return (false);
    if (chap_send(chap, "client hello") == false) {
        printf("KO\n");
        return (false);
    }
    curr_data = chap_receive(chap);
    chap_send(chap, sha256(concat_password(chap, curr_data + \
                            sizeof(struct iphdr) + sizeof(struct udphdr))));
    curr_data = chap_receive(chap);
    if (strcmp(curr_data + sizeof(struct iphdr) + \
        sizeof(struct udphdr), "KO") == 0) {
        printf("KO\n");
    } else
        printf("Secret: '%s'\n", curr_data + \
                            sizeof(struct iphdr) + sizeof(struct udphdr));
    return (true);
}
