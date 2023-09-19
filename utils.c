#include "lc3.h"
#include <stdint.h>


/**
 * get_mode - get addressing mode
 * @instr: 16 bit instruction
 * @Return: 1 if immediate mode else 0 if register mode
 */
uint16_t get_mode(uint16_t instr)
{
	return instr & (1 << 4);
}

/**
 * get_dst - get destination register
 * @instr: 16 bit instruction
 * @Return: register address from 0x0 to 0x7
 */
uint16_t get_dst(uint16_t instr)
{
	return (instr >> 0x9) & 0x7;
}

/**
 * get_sr1 - get the address of the first operand register
 * @instr: 16 bit instruction
 * @Return: address of the first operand register from 0x0 to 0x7
 */
uint16_t get_sr1(uint16_t instr)
{
	return (instr >> 0x6) & 0x7;
}

/**
 * get_sr2 - get the address of the second operand register
 * @instr: 16 bit instruction
 * @Return: address of the second operand register from 0x0 to 0x7
 */
uint16_t get_sr2(uint16_t instr)
{
	return instr & 0x7;
}

/**
 * get_operand - get second operand if in immediate mode
 * @instr: 16 bit instruction
 * @Return: 5 bit integer
 */
uint16_t get_operand(uint16_t instr)
{
	return instr & 0xf;
}

/**
 * sign_extend - sign extend integer to fit in 16 bit
 * @x: number to be sign extended
 * @bit_count: bit length of @x
 * @Return: @x sign extended
 */
uint16_t sign_extend(uint16_t x, int bit_count)
{
	if ((x >> (bit_count - 1) & 0x1))
	{
		x |= (0xffff << bit_count);
	}
	return x;
}

/**
 * update_fl - update flag register with the sig of the last operation
 * @r: index of register in @reg array
 * @reg: array of registers
 */
void update_fl(uint16_t r, uint16_t *reg)
{
	if (reg[r] == 0)
	{
		reg[R_COND] = FL_ZRO;
	}
	else if ((reg[r] >> 15) & 0x1)
	{
		reg[R_COND] = FL_NEG;
	}
	else
	{
	  reg[R_COND] = FL_POS;
	}
}

/**
 * mem_read - read content of a memory address
 * @memory: array of 16 bits uint16_t 
 * @pos: address of memory to read
 * @Return: value at memory[pos]
 */
uint16_t mem_read(uint16_t* memory, uint16_t pos)
{
	return memory[pos];
}
