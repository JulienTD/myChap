/*
** EPITECH PROJECT, 2019
** myChap
** File description:
** packet_calculate_checksum
*/

#include "packet.h"

bool packet_calculate_checksum(packet_t *packet)
{
    packet->udph->check = 0;
    return (true);
}