#include"emulatorbody.h"
#include"emu_init_funcs.h"
#include "pipeline.h"

word registers[7] = {01,02,03,04,05,00,00};
word IR = 00; // Instruction Register
word operand1 = 00;
word operand2 = 00;
word PC = 0140000;
byte MEMORY[MEM_SIZE];

//byte PDP_MEMORY[MEM_SIZE];

bool StartEmu(){
//    InitializeMemory(MEMORY);
    testPipeline();
    return false;
}

byte *GetPointerToVRAM(){
//    return &MEMORY[VRAM_START_INDEX];
    return &MEMORY[PC];
}
