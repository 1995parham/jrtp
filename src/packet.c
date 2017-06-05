/*
 * In The Name Of God
 * ========================================
 * [] File Name : packet.c
 *
 * [] Creation Date : 05-06-2017
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2017 Parham Alvani.
*/


#include "packet.h"


int rtp_packet_serialize(const struct rtp_packet *p, uint8_t *buff)
{
	/* buff[0] = (V << 6 | P << 5 | X << 4 | CC) */
	buff[0] = (2 << 6 | 0 << 5 | 0 << 4 | 0);
	/* buff[1] = (M << 7 | PT) */
	buff[1] = (0 << 7 | p->payload_type);
	/* buff[2, 3] = SN */
	buff[2] = p->sequence_number >> 8;
	buff[3] = p->sequence_number;
	/* buff[4, 5, 6, 7] = TS */
	buff[4] = p->timestamp >> 24;
	buff[5] = p->timestamp >> 16;
	buff[6] = p->timestamp >> 8;
	buff[7] = p->timestamp;
	/* buff[4, 5, 6, 7] = SSRC */
	buff[8] = p->ssrc >> 24;
	buff[9] = p->ssrc >> 16;
	buff[10] = p->ssrc >> 8;
	buff[11] = p->ssrc;
	
	int i = 0;
	while (p->payload[i] != 0) {
		buff[12 + i] = p->payload[i];
	}
}

int rtp_packet_deserialize(struct rtp_packet *p, const uint8_t *buff)
{
}
