#include "lc3.h"

uint16_t image_load(uint16_t* image, uint16_t* reg, uint16_t* memory)
{
	uint16_t pc = reg[R_PC] + 0x1;
	uint16_t i = 0;

	while((image[i] != 0) && (memory[pc++] = image[i++]));
	return 1;
}


