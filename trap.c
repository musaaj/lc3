#include <stdlib.h>
#include <unistd.h>
#include "lc3.h"


void trap(uint16_t instr, uint16_t* memory, uint16_t* reg)
{
	reg[R_R7] = reg[R_PC];
	uint16_t vector = instr & 0xff;
	reg[R_PC] = vector;
	switch (vector)
	{
		case TRAP_GETC:
			reg[R_R0] = _getc();
			write(STDIN_FILENO, &reg[R_R0], 1);
			break;
		case TRAP_OUT:
			write(STDIN_FILENO, &reg[R_R0], 1);
			break;
		case TRAP_PUTS:
			_puts(memory, reg);
			break;
		case TRAP_IN:
			reg[R_R0] = _getc();
			break;
		case TRAP_PUTSP:
			_puts(memory, reg);
			break;
		case TRAP_HALT:
			puts("Halt");
			exit(EXIT_SUCCESS);
			break;
	}
	reg[R_PC] = reg[R_R7];
}
