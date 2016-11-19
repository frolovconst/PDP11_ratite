#include"pipelatz.h"


#include<stdio.h>
bool RenderVRAMPartition(byte MEM[MEM_SIZE]){
    int i;
    bool picBit;
    byte *VRAMpointer  = &MEM[VRAM_START_INDEX];
    for(i = 0; i < VRAM_WIDTH * 3; i++){
            picBit = (VRAMpointer[i/8] >> (7-i%8))&1;
            printf("%d", picBit);
            if((i + 1) % VRAM_WIDTH == 0)
                printf("\n");
        }
    return false;
}

bool ExecuteNextInstructionSet(byte MEMORY[MEM_SIZE]){
    word IR;
    word PC = getWordInByteArray(MEMORY, PC_INDX);
    while (MEMORY[PC]) {
            IR = fetch(MEMORY);
            DecodeAndExecute(IR, MEMORY);
//            RenderVRAMPartition(MEMORY);
            PC = getWordInByteArray(MEMORY, PC_INDX);
        }
    return false;
}

word fetch(byte mem[MEM_SIZE]) {
   word PC = getWordInByteArray(mem, PC_INDX);
   word IR = getWordInByteArray(mem, PC);
   setWordInByteArray(mem, PC_INDX, PC + 2);
   return IR;
}




