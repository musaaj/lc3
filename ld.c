#include "lc3.h"


void ld(uint16_t instr, uint16_t* mem, uint16_t* reg)
{
	uint16_t dst = (instr >> 0x9) & 0x7;
	uint16_t offset = instr & 0x1ff;
	uint16_t val = reg[R_PC] + sign_extend(offset, NINE_BIT);
	reg[dst] = mem_read(mem, val);
	update_fl(dst, reg);
}
