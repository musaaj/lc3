#include "lc3.h"


void jsr(uint16_t instr, uint16_t* reg)
{
	reg[R_R7] = reg[R_PC];
	if ( (instr >> 0xb) & 0x1)
	{
		uint16_t offset = instr & 0x7ff;
		reg[R_PC] += sign_extend(offset, ELEVEN_BIT);
	}
	else
	{
		uint16_t base_r = (instr >> 0x6) & 0x7;
		reg[R_PC] = reg[base_r];
	}
}
