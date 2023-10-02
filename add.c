#include "lc3.h"

/**
 * add - add values from two registers or from
 * a register and an embedded value and store in
 * a destination register
 * @instr: 16 bit integer containing the opcode
 * and its operands
 * @reg: array of registers
 */
void add(uint16_t instr, uint16_t* reg)
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
	update_fl(dst, reg);
}
