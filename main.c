#include <stdlib.h>
#include "lc3.h"

uint16_t reg[R_COUNT];
uint16_t memory[MEMORY_MAX];
uint16_t prog[] = {
	0x0003,
	0x5220,
	0x1235,
	0x1241,
	0x1241,
	0x1241,
	0x0302,
	0xf020,
	0xf023,
	0xf021,
	0xf022,
	0xf025
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
				ld(instr, memory, reg);
				break;
			case OP_ST:
				st(instr, memory, reg);
				break;
			case OP_JSR:
				jsr(instr, reg);
				break;
			case OP_AND:
				_and(instr, reg);
				break;
			case OP_LDR:
				ldr(instr, memory, reg);
				break;
			case OP_STR:
				str(instr, memory, reg);
				break;
			case OP_RTI:
				break;
			case OP_NOT:
				_not(instr, reg);
				break;
			case OP_LDI:
				ldi(instr, memory, reg);
				break;
			case OP_STI:
				sti(instr, memory, reg);
				break;
			case OP_JMP:
				jmp(instr, reg);
				break;
			case OP_RES:
				break;
			case OP_LEA:
				lea(instr, reg);
				break;
			case OP_TRAP:
				trap(instr, memory, reg);
				break;
			default:
				break;

		}
	}
	return 0;
}
