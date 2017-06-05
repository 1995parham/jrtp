/*
 * In The Name Of God
 * ========================================
 * [] File Name : RTPPacket.h
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

class RTPPacket {
	public:
		RTPPacket(uint8_t *payload, uint16_t sequenceNumber, uint32_t ssrc, uint32_t timestamp) : RTPPacket(payload, sequenceNumber, ssrc, timestamp, 95) {};
		RTPPacket(uint8_t *payload, uint16_t sequenceNumber, uint32_t ssrc) : RTPPacket(payload, sequenceNumber, ssrc, 0, 95) {};
		RTPPacket(uint8_t *payload, uint16_t sequenceNumber, uint32_t ssrc, uint32_t timestamp, uint8_t payloadType);
		RTPPacket(const RTPPacket& src) = default;

		int serialize(uint8_t *buff) const;
		int deserialize(const uint8_t *buff);

		uint8_t *getPayload() const;
		void setPayload(uint8_t *payload);

	private:
		uint8_t *payload;
		uint16_t sequenceNumber;
		uint32_t ssrc;
		uint32_t timestamp;
		uint8_t payloadType;
};


#endif
