#include"emulatorbody.h"
#include"emu_init_funcs.h"

byte PDP_MEMORY[MEM_SIZE];

bool StartEmu(){
    InitializeMemory(PDP_MEMORY);
    return false;
}

byte *GetPointerToVRAM(){
    return &PDP_MEMORY[VRAM_START_INDEX];
}
