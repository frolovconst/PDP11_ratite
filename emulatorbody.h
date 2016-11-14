#include "emu_init_funcs.h"
#ifndef EMULATORBODY_H
#define EMULATORBODY_H
#include<stdbool.h>

bool StartEmu();
bool InitializeMemory(byte *);
byte *GetPointerToVRAM();

#endif // EMULATORBODY_H
