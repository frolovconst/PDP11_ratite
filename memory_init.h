#include"ratite_mem_funcs.h"

#ifndef MEMORY_INIT_H
#define MEMORY_INIT_H


bool InitializeMemory(byte [MEM_SIZE]);
bool CopyLogoToROM(const char *, byte [MEM_SIZE]);
bool InitializePC(byte [MEM_SIZE]);
bool ResetMEM(byte [MEM_SIZE]);
bool InitializeROM(byte [MEM_SIZE]);
bool CopyLogoToVRAM(byte [MEM_SIZE]);

#endif // MEMORY_INIT_H
