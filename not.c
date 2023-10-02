#include "lc3.h"


void _not(uint16_t instr, uint16_t* reg)
{
	uint16_t src = (instr >> 0x6) & 0x7;
	uint16_t dst = (instr >> 0x9) & 0x7;
	reg[dst] = ~reg[src];
	update_fl(dst, reg);
}
