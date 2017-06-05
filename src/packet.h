/*
 * In The Name Of God
 * ========================================
 * [] File Name : packet.h
 *
 * [] Creation Date : 05-06-2017
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2017 Parham Alvani.
*/
#ifndef packet_h
#define packet_h

#include <inttypes.h>

struct rtp_packet {
	uint8_t *payload;
	uint16_t sequence_number;
	uint32_t ssrc;
	uint32_t timestamp;
	uint8_t payload_type;
};

int rtp_packet_serialize(const struct rtp_packet *p, uint8_t *buff);

int rtp_packet_deserialize(struct rtp_packet *p, const uint8_t *buff);

#endif
