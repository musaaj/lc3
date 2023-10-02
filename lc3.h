#ifndef LC3_H
#define LC3_H

/*includes*/
#include <stdio.h>
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
	FL_POS = 1 << 0,
	FL_ZRO = 1 << 1,
	FL_NEG = 1 << 0
};

enum {
	PC_START = 0x3000
};

enum {
	FIVE_BIT = 4,
	NINE_BIT = 9,
	ELEVEN_BIT = 10,
	SIX_BIT = 6
};

enum {
	TRAP_GETC = 0x20,
	TRAP_OUT = 0x21,
	TRAP_PUTS = 0x22,
	TRAP_IN = 0x23,
	TRAP_PUTSP = 0x24,
	TRAP_HALT = 0x25
};


uint16_t mem_read(uint16_t* mem_read, uint16_t idx);
uint16_t read_image(char* filename);
uint16_t image_load(uint16_t*, uint16_t*, uint16_t*);

void add(uint16_t instr, uint16_t * reg);
void _and(uint16_t instr, uint16_t*);
void _not(uint16_t instr, uint16_t* reg);
void ldi(uint16_t instr, uint16_t* memory, uint16_t* reg);
void br(uint16_t instr, uint16_t* reg);
void jmp(uint16_t instr, uint16_t*);
void jsr(uint16_t instr, uint16_t*);
void ld(uint16_t, uint16_t* memory, uint16_t* reg);
void ldr(uint16_t instr, uint16_t* memory, uint16_t* reg);
void lea(uint16_t instr, uint16_t* reg);
void st(uint16_t instr, uint16_t* memory, uint16_t* reg);
void sti(uint16_t instr, uint16_t* memory, uint16_t* reg);
void str(uint16_t instr, uint16_t* memory, uint16_t* reg);
void trap(uint16_t instr, uint16_t* memory, uint16_t* reg);


uint16_t get_mode(uint16_t instr);
uint16_t get_dst(uint16_t instr);
uint16_t get_sr1(uint16_t instr);
uint16_t get_sr2(uint16_t instr);
uint16_t get_operand(uint16_t instr);

uint16_t sign_extend(uint16_t x, int bit_count);
void update_fl(uint16_t r, uint16_t *);

//traps
uint16_t _getc(void);
void _puts(uint16_t* memory, uint16_t* reg);
void _putsp(uint16_t* memory, uint16_t* reg);
#endif
