#include "lc3.h"


void st(uint16_t instr, uint16_t* memory, uint16_t* reg)
{
	uint16_t offset = instr & 0x1ff;
	uint16_t src = (instr >> 0x9) & 0x7;
	memory[reg[R_PC] + sign_extend(offset, NINE_BIT)] = reg[src];
}
