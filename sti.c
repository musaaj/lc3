#include "lc3.h"

/**
 * sti - store address of data in a memory location
 * @instr: 16 instruction
 * @memory: memory array
 * @reg: registers array
 */
void sti(uint16_t instr, uint16_t* memory, uint16_t* reg)
{
	uint16_t offset = instr & 0x1ff;
	uint16_t src = (instr >> 0x9) & 0x7;
	memory[memory[reg[R_PC] + sign_extend(offset, NINE_BIT)]] = reg[src];
}
