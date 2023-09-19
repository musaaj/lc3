#include "lc3.h"
#include <stdlib.h>


/**
 * br - conditionally branch to a memory location
 * @instr: 16 bit instruction
 * @reg: array of registers
 * @memory: array of memory
 */
void br(uint16_t instr, uint16_t* reg)
{
	uint16_t condition = get_dst(instr); //reuse
	uint16_t offset = instr & 0x1ff;
	if (reg[R_COND] == condition)
	{
		reg[R_PC] = reg[R_PC] - sign_extend(offset, NINE_BIT);
	}
}
