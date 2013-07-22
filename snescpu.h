#include <stdint.h>

#define P_BIT_E		0x0100
#define P_BIT_N		0x0080
#define P_BIT_V		0x0040
#define P_BIT_M		0x0020
#define P_BIT_X		0x0010
#define P_BIT_D		0x0008
#define P_BIT_I		0x0004
#define P_BIT_Z		0x0002
#define P_BIT_C		0x0001

//XXX: i don't know how arrayviews / endianness will affect the ordering of this
struct snescpu_reg {
	union {
		struct {
			uint8_t A;
			uint8_t B;
		};
		uint16_t C;
	};
	uint16_t X;
	uint16_t Y;
	uint16_t D;
	uint16_t S;
	uint16_t PC;

	uint8_t DBR;
	uint8_t PBR;

	uint16_t P;
};
