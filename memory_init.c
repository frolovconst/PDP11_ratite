#include "definitions.h"
#include "memory_init.h"
#include <stdio.h>

const char *LOGO_PATH = "../PDP11_ratite/files/logo.txt";

bool InitializeMemory(byte mem[MEM_SIZE], word *PC){
    ResetMEM(mem);
    CopyLogoToROM(LOGO_PATH, mem);
    //TODO: Implement PC initializaion
    //InitializePC(mem);
    *PC = 0140000;
    setWordInByteArray(mem, *PC, 010102);            // MOVB R2,R3
    return true;
}

bool CopyLogoToROM(const char *logoPath, byte mem[MEM_SIZE]){
    int i;
    FILE *logoBin;
    logoBin = fopen(logoPath, "rb");
    for(i = 0; i < IMG_WIDTH * IMG_WIDTH / 8; i++){
        fscanf(logoBin,"%c",&mem[i + LOGO_START_INDEX]);
    }
    fclose(logoBin);
    return false;
}

bool InitializePC(byte mem[MEM_SIZE]){
    printf("Fix me %d", mem[0]);
    return false;
}

bool ResetMEM(byte mem[MEM_SIZE]){
    int i;
    for(i = 0; i < MEM_SIZE; i++){
        mem[i] = 0;
    }
    setWordInByteArray(mem, REG_START_ADDR + 2, 257);
    return false;
}
