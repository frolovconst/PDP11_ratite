#include"definitions.h"
#include "memory_init.h"
#include"pipelatz.h"
#ifndef RATITE_BODY_H
#define RATITE_BODY_H

bool Start();
bool Step();
bool WriteMemoryStateToFile(byte [MEM_SIZE], word );
bool ReadMemoryStateFromFile(byte [MEM_SIZE], word *);
byte *GetPointerToVRAM();

#endif // RATITE_BODY_H
