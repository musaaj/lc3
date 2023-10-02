#include "lc3.h"


void lea(uint16_t instr, uint16_t* reg)
{
	uint16_t offset = instr & 0x1ff;
	uint16_t dst = (instr >> 0x9) & 0x7;
	reg[dst] = reg[R_PC] + sign_extend(offset, NINE_BIT);
	update_fl(dst, reg);
}
