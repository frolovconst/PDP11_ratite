#include"emulatorbody.h"
#include"emu_init_funcs.h"

byte PDP_MEMORY[MEM_SIZE];

bool StartEmu(){
    InitializeMemory(PDP_MEMORY);
    return false;
}
