#include "lc3.h"


void jmp(uint16_t instr, uint16_t* reg)
{
	uint16_t base_r = (instr >> 0x6) & 0x7;
	reg[R_R7] = reg[R_PC];
	reg[R_PC] = reg[base_r];
}
