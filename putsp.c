#include <unistd.h>
#include "lc3.h"


void _putsp(uint16_t* memory, uint16_t* reg)
{
	uint16_t* c = &memory[reg[R_R0]];

	while (*c)
	{
		char c1 = *c & 0x00ff;
		char c2 = *c >> 8;

		write(STDIN_FILENO, &c1, 1);
		if (c2)
		{
			write(STDIN_FILENO, &c2, 1);
		}
		else return;
		c++;
	}
}
