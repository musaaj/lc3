#include <stdlib.h>
#include "lc3.h"

uint16_t reg[R_COUNT];
uint16_t memory[MEMORY_MAX];
uint16_t prog[] = {
	0x5220,
	0x1235,
	0x1241,
	0x1241,
	0x1241,
	0x0284,
	0xf000
};


int main(void)
{
	int running = 1;

	reg[R_PC] = PC_START;
	reg[R_COND] = FL_ZRO;
	image_load(prog, reg, memory);

	while(running)
	{
		uint16_t instr = mem_read(memory, reg[R_PC]++);
		uint16_t opcode = instr >> 12;
		switch (opcode)
		{
			case OP_BR:
				br(instr, reg);
				break;
			case OP_ADD:
				add(instr, reg);
				break;
			case OP_LD:
				break;
			case OP_ST:
				break;
			case OP_JSR:
				break;
			case OP_AND:
				_and(instr, reg);
				break;
			case OP_LDR:
				break;
			case OP_STR:
				break;
			case OP_RTI:
				break;
			case OP_NOT:
				break;
			case OP_LDI:
				break;
			case OP_STI:
				break;
			case OP_JMP:
				break;
			case OP_RES:
				break;
			case OP_LEA:
				break;
			case OP_TRAP:
				exit(EXIT_SUCCESS);
				break;
			default:
				break;

		}
	}
	return 0;
}
