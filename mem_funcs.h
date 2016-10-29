#ifndef MEM_FUNCS_H
#define MEM_FUNCS_H
#include "emu_init_funcs.h"

void printRegisters() ;

bool getBitInWord(word inByte, int index);

byte getTriade(word inByte, int index);

void setWord(int address, word _word);
word getWord(int address);


#endif // MEM_FUNCS_H
