

extern const unsigned int crcTab[256];

#define UPDATECRC(crc,c) (crcTab[(((crc) >> 8) & 0xFF)] ^ ((crc) << 8) ^ (c))

