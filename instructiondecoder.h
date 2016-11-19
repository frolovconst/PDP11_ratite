#include"definitions.h"
#include"ratite_mem_funcs.h"
#include"ratite_instructions.h"
#ifndef INSTRUCTIONDECODER_H
#define INSTRUCTIONDECODER_H

#define MODE0 00
#define MODE1 01
#define MODE2 02
#define MODE4 04
#define MODE6 06

#define INC 052
#define SOB 07
#define ADD 06

#define SINGLE_OPERAND 0

bool DecodeAndExecute(word, byte[MEM_SIZE]);
int DecodeDoubleInstOperand(word , int ,  byte [MEM_SIZE]);
int readOperand(byte , byte, byte [MEM_SIZE]);

#endif // INSTRUCTIONDECODER_H
