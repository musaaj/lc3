#include "lc3.h"

uint16_t image_load(uint16_t* image, uint16_t* reg, uint16_t* memory)
{
	(void) reg;
	uint16_t pc = image[0];
	uint16_t i = 1;

	while((image[i] != 0) && (memory[pc++] = image[i++]));
	return 1;
}
