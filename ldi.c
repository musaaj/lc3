#include "lc3.h"

void ldi(uint16_t instr, uint16_t* reg, uint16_t* memory)
{
	uint16_t dst = get_dst(instr);
	uint16_t offset = sign_extend(instr & 0x1ff, NINE_BIT);

	reg[dst] = mem_read(memory, mem_read(memory, reg[R_PC] + offset));
}

