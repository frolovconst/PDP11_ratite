#include "definitions.h"
#include "memory_init.h"
#include <stdio.h>

const char *LOGO_PATH = "../PDP11_ratite/files/logo.txt";

bool InitializeMemory(byte mem[MEM_SIZE]){
    ResetMEM(mem);
    CopyLogoToROM(LOGO_PATH, mem);
    InitializePC(mem);
    InitializeVRAM(mem);
//    DebugInstrs(mem);
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
    setWordInByteArray(mem, PC_INDX, 49152);
    return false;
}

bool ResetMEM(byte mem[MEM_SIZE]){
    int i;
    for(i = 0; i < MEM_SIZE; i++){
        mem[i] = 0;
    }
    return false;
}

bool InitializeVRAM(byte mem[MEM_SIZE]){
    CopyLogoToVRAM(mem);
    return false;
}

bool CopyLogoToVRAM(byte mem[MEM_SIZE]){
    word writeIndex = ROM_START_INDEX;
    setWordInByteArray(mem, writeIndex, 012702);            // init line sob
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 64);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 012700);            // init ROM start
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, LOGO_START_INDEX);            // ADD #5
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 012701);            // init VRAM start
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, VRAM_START_INDEX + 3084);            // ADD #5
    writeIndex += 2;


    setWordInByteArray(mem, writeIndex, 012703);            // init inline sob
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 4);            // ADD #5
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 012021);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 077302);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 062701);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 24);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 077207);
    writeIndex += 2;

    return false;
}

bool DebugInstrs(byte mem[MEM_SIZE]){
    //test data
    setWordInByteArray(mem, LOGO_START_INDEX, 65534);
    setWordInByteArray(mem, LOGO_START_INDEX + 2, 65534);


    word writeIndex = ROM_START_INDEX;
    setWordInByteArray(mem, writeIndex, 012700);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, LOGO_START_INDEX);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 012701);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, VRAM_START_INDEX);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 012021);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 062701);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 62);
    writeIndex += 2;
    setWordInByteArray(mem, writeIndex, 012021);
    writeIndex += 2;

//    setWordInByteArray(mem, writeIndex, 65535);
//    writeIndex += 2;
    return false;
}
