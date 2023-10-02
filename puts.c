#include <unistd.h>
#include "lc3.h"


void _puts(uint16_t* memory, uint16_t* reg)
{
	uint16_t* c = &(memory[reg[R_R0]]);
	while (*c)
	{
		write(STDIN_FILENO, c, 1);
		c++;
	}
}
