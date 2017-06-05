#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <RTPPacket.h>


// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
	0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 73, 9);

char packetBuffer[255];

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

void setup() {
	// start the Ethernet and UDP:
	Ethernet.begin(mac, ip);
	Udp.begin(1373);

	Serial.begin(9600);
}

void loop() {
	RTPPacket("Hello", 0, 0).serialize(packetBuffer);

	Udp.beginPacket(ip(192, 168, 73, 2), 1373);
	Udp.write(packetBuffer);
	Udp.endPacket();

	delay(10);
}
