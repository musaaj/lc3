#include "lc3.h"


void ldr(uint16_t instr, uint16_t* mem, uint16_t* reg)
{
	uint16_t offset = instr & 0x3f;
	uint16_t src = (instr >> 0x6) & 0x7;
	uint16_t dst = (instr >> 0x9) & 0x7;
	reg[dst] = mem_read(mem, reg[src] + sign_extend(offset, SIX_BIT));
	update_fl(dst, reg);
}
