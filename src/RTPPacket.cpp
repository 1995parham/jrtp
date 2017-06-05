/*
 * In The Name Of God
 * ========================================
 * [] File Name : RTPPacket.cpp
 *
 * [] Creation Date : 05-06-2017
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2017 Parham Alvani.
*/


#include "RTPPacket.h"

RTPPacket::RTPPacket(uint8_t *payload, uint16_t sequenceNumber, uint32_t ssrc, uint32_t timestamp, uint8_t payloadType){
}

int RTPPacket::serialize(uint8_t *buff) const
{
	/* buff[0] = (V << 6 | P << 5 | X << 4 | CC) */
	buff[0] = (2 << 6 | 0 << 5 | 0 << 4 | 0);
	/* buff[1] = (M << 7 | PT) */
	buff[1] = (0 << 7 | this->payloadType);
	/* buff[2, 3] = SN */
	buff[2] = this->sequenceNumber >> 8;
	buff[3] = this->sequenceNumber;
	/* buff[4, 5, 6, 7] = TS */
	buff[4] = this->timestamp >> 24;
	buff[5] = this->timestamp >> 16;
	buff[6] = this->timestamp >> 8;
	buff[7] = this->timestamp;
	/* buff[4, 5, 6, 7] = SSRC */
	buff[8] = this->ssrc >> 24;
	buff[9] = this->ssrc >> 16;
	buff[10] = this->ssrc >> 8;
	buff[11] = this->ssrc;
	
	int i = 0;
	while (this->payload[i] != 0) {
		buff[12 + i] = this->payload[i];
	}
	buff[12 + i] = 0;

	return i + 12;
}

int RTPPacket::deserialize(const uint8_t *buff)
{
}

uint8_t *RTPPacket::getPayload() const
{
	return this->payload;
}
