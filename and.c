#include "lc3.h"

/**
 * _and - perform logical and on operands and store the result
 * @instr: 16 bit instruction
 * @reg: array of registers
 */
void _and(uint16_t instr, uint16_t* reg)
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

	update_fl(dst, reg);
}


