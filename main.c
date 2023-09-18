#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lc3.h"

uint16_t reg[R_COUNT];
uint16_t memory[MEMORY_MAX];
uint16_t prog[] = {
	0x5210,
	0x1235,
	0x1241,
	0x1241,
	0x5210,
	0xf000
};


int main(void)
{
	int running = 1;

	reg[R_PC] = PC_START;
	reg[R_COND] = FL_ZRO;
	image_load(prog);

	while(running)
	{
		uint16_t instr = mem_read(reg[R_PC]++);
		uint16_t opcode = instr >> 12;
		
		switch (opcode)
		{
			case OP_BR:
				break;
			case OP_ADD:
				add(instr);
				break;
			case OP_LD:
				break;
			case OP_ST:
				break;
			case OP_JSR:
				break;
			case OP_AND:
				_and(instr);
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


uint16_t mem_read(uint16_t pos)
{
	return memory[pos];
}

uint16_t image_load(uint16_t image[])
{
	uint16_t pc = reg[R_PC] + 0x1;
	uint16_t i = 0;

	while((image[i] != 0) && (memory[pc++] = image[i++]));
	return 1;
}


uint16_t add(uint16_t instr)
{
	uint16_t dst = get_dst(instr);
	uint16_t imm = get_mode(instr);
	uint16_t sr1 = get_sr1(instr);
	
	if(imm)
	{
		uint16_t operand = get_operand(instr);
		reg[dst] = reg[sr1] + sign_extend(operand, FIVE_BIT);
	}else
	{
	  uint16_t sr2 = get_sr2(instr);
	  reg[dst] = reg[sr1] + reg[sr2];
	}
	update_fl(dst);
	return 1;
}


uint16_t _and(uint16_t instr)
{
	uint16_t dst = get_dst(instr);
	uint16_t sr1 = get_sr1(instr);
	uint16_t imm = get_mode(instr);

	if (imm)
	{
		uint16_t operand = get_operand(instr);
		reg[dst] = reg[sr1] & sign_extend(operand, FIVE_BIT);
	}else
	{
	  uint16_t sr2 = get_sr2(instr);
	  reg[dst] = reg[sr1] & reg[sr2];
	}

	update_fl(dst);
	return 1;
}


uint16_t ldi(uint16_t instr)
{
	uint16_t dst = get_dst(instr);
	uint16_t offset = sign_extend(instr & 0x1ff, NINE_BIT);

	reg[dst] = mem_read(mem_read(reg[R_PC] + offset));
	return 1;
}


uint16_t get_mode(uint16_t instr)
{
	return instr & (1 << 4);
}


uint16_t get_dst(uint16_t instr)
{
	return (instr >> 0x9) & 0x7;
}

/**
 * get_sr1 - get the address of the first operand register
 * @instr: machine instruction
 * @Return: address of the first operand register
 */
uint16_t get_sr1(uint16_t instr)
{
	return (instr >> 0x6) & 0x7;
}


uint16_t get_sr2(uint16_t instr)
{
	return instr & 0x7;
}


uint16_t get_operand(uint16_t instr)
{
	return instr & 15;
}

uint16_t sign_extend(uint16_t x, int bit_count)
{
	if ((x >> (bit_count - 1) & 0x1))
	{
		x |= (0xffff << bit_count);
	}
	return x;
}

void update_fl(uint16_t r)
{
	if (reg[r] == 0)
	{
		reg[R_COND] = FL_ZRO;
		return;
	}

	if ((reg[r] >> 15) & 0x1)
	{
		reg[R_COND] = FL_NEG;
		return;
	}

	reg[R_COND] = FL_POS;
}
