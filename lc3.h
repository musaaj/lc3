#ifndef LC3_H
#define LC3_H

/*includes*/
#include <stdio.h>
#include <bits/stdint-uintn.h>
#include <stdint.h>

/*defines*/
#define MEMORY_MAX (1<<16)


/**
 * registers addresses
 */
enum{
	R_R0,
	R_R1,
	R_R2,
	R_R3,
	R_R4,
	R_R5,
	R_R6,
	R_R7,
	R_PC,
	R_COND,
	R_COUNT
};

/**
 * opcodes
 */
enum {
	OP_BR, //branch
	OP_ADD, //addition
	OP_LD, //load memory address
	OP_ST, //store in memory address
	OP_JSR, 
	OP_AND,
	OP_LDR,
	OP_STR,
	OP_RTI,
	OP_NOT,
	OP_LDI,
	OP_STI,
	OP_JMP,
	OP_RES,
	OP_LEA,
	OP_TRAP
};

enum {
	FL_POS = 1 < 0,
	FL_ZRO = 1 < 1,
	FL_NEG = 1 < 2
};

enum {
	PC_START = 0x3000
};

enum {
	FIVE_BIT = 4,
	NINE_BIT = 9,
};


uint16_t mem_read(uint16_t*, uint16_t);
uint16_t read_image(char*);
uint16_t image_load(uint16_t*, uint16_t*, uint16_t*);

void add(uint16_t instr, uint16_t *);
void _and(uint16_t instr, uint16_t*);
void ldi(uint16_t instr, uint16_t*, uint16_t*);

uint16_t get_mode(uint16_t instr);
uint16_t get_dst(uint16_t instr);
uint16_t get_sr1(uint16_t instr);
uint16_t get_sr2(uint16_t instr);
uint16_t get_operand(uint16_t instr);

uint16_t sign_extend(uint16_t x, int bit_count);
void update_fl(uint16_t r, uint16_t *);
#endif
