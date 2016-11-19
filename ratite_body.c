
#include"ratite_body.h"
#include <stdio.h>

byte MEMORY[MEM_SIZE];
const char *MEM_STATE_FILE_PATH = "../PDP11_ratite/files/mem.txt";

bool Start(){
    InitializeMemory(MEMORY);
    WriteMemoryStateToFile(MEMORY);
    return false;
}

bool Step(){
    ReadMemoryStateFromFile(MEMORY);
    ExecuteNextInstructionSet(MEMORY);
    WriteMemoryStateToFile(MEMORY);
    return false;
}

byte *GetPointerToVRAM(){
    return &MEMORY[VRAM_START_INDEX];
}

bool WriteMemoryStateToFile(byte mem[MEM_SIZE]){
    int i;
    FILE *memState;
    memState = fopen(MEM_STATE_FILE_PATH, "wb");
    for(i = 0; i < MEM_SIZE ; i++){
        fprintf(memState,"%c",mem[i]);
    }
    fclose(memState);
    return false;
}

bool ReadMemoryStateFromFile(byte mem[MEM_SIZE]){
    int i;
    FILE *memState;
    memState = fopen(MEM_STATE_FILE_PATH, "rb");
    for(i = 0; i < MEM_SIZE ; i++){
        fscanf(memState,"%c",&mem[i]);
    }
    fclose(memState);
    return false;
    return false;
}

