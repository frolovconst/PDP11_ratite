
#include"ratite_body.h"
#include <stdio.h>

byte MEMORY[MEM_SIZE];
word PC;
const char *MEM_STATE_FILE_PATH = "../PDP11_ratite/files/mem.txt";

bool Start(){
    InitializeMemory(MEMORY, &PC);
    WriteMemoryStateToFile(MEMORY, PC);
    return false;
}

bool Step(){
    ReadMemoryStateFromFile(MEMORY, &PC);
    ExecuteNextInstructionSet(MEMORY, &PC);
    WriteMemoryStateToFile(MEMORY, PC);
    PC ++;
    ReadMemoryStateFromFile(MEMORY, &PC);
    return false;
}

byte *GetPointerToVRAM(){
    return &MEMORY[LOGO_START_INDEX];
//    return &MEMORY[PC];
}

bool WriteMemoryStateToFile(byte mem[MEM_SIZE], word PrgCnt){
    int i, lclPC = PrgCnt;
    FILE *memState;
    memState = fopen(MEM_STATE_FILE_PATH, "wb");
    fprintf(memState,"%d",lclPC);
    for(i = 0; i < MEM_SIZE ; i++){
        fprintf(memState,"%c",mem[i]);
    }
    fclose(memState);
    return false;
}

bool ReadMemoryStateFromFile(byte mem[MEM_SIZE], word *PrgCnt){
    int i, lclPC;
    FILE *memState;
    memState = fopen(MEM_STATE_FILE_PATH, "rb");
    fscanf(memState,"%d",&lclPC);
    *PrgCnt = lclPC;
    for(i = 0; i < MEM_SIZE ; i++){
        fscanf(memState,"%c",&mem[i]);
    }
    fclose(memState);
    return false;
    return false;
}

