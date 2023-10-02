#include "lc3.h"


void str(uint16_t instr, uint16_t* memory, uint16_t* reg)
{
	uint16_t offset = instr & 0x3f;
	uint16_t base_r = (instr >> 0x6) & 0x7;
	uint16_t src = (instr >> 0x9) & 0x7;
	memory[base_r + sign_extend(offset, SIX_BIT)] = reg[src];
}
