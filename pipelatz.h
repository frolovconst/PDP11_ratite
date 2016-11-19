#include"definitions.h"
#include"ratite_mem_funcs.h"
#include"instructiondecoder.h"
#ifndef PIPELATZ_H
#define PIPELATZ_H

bool ExecuteNextInstructionSet(byte [MEM_SIZE]);
word fetch(byte [MEM_SIZE]);

#endif // PIPELATZ_H
