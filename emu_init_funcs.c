#include "emu_init_funcs.h"
#include <stdio.h>



//Fair work
////////////////////////////////////////////////////////////////////////////////


const char *LOGO_PATH = "../PDP11_ratite/files/logo.txt";

bool InitializeMemory(byte mem[MEM_SIZE]){
    ResetMEM(mem);
    CopyLogoToROM(LOGO_PATH, mem);
    //TODO: Implement PC initializaion
    InitializePC(mem);
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
    return false;
}

bool ResetMEM(byte mem[MEM_SIZE]){
    int i;
    for(i = 0; i < MEM_SIZE; i++){
        mem[i] = 0;
    }
    return false;
}


bool GetBitInByte(byte inByte, int index) {
    return (inByte >> (7 - index)) & 1;
}

void SetBitInByte(byte *inByte, int index, bool value) {
    if (value) {
        byte aux = 1 << (7 - index);
        *inByte = (*inByte) | aux;
    }
    else {
        byte aux = 255 - pow(2,7-index);
        *inByte = (*inByte) & aux;
    }
}

void SetBitInByteArray(byte *array, int index, bool value){
    int byteIndex = index / 8;
    int bitIndex = index % 8;
    SetBitInByte(&array[byteIndex], bitIndex, value);
}

bool GetBitInByteArray(byte *array, int index){
    int byteIndex = index / 8;
    int bitIndex = index % 8;
    return GetBitInByte(array[byteIndex], bitIndex);
}


//Draft work
////////////////////////////////////////////////////////////////////////////////
void CreateBinLogo(char path[], char resultPath[]) {
    //const int IMG_WIDTH=64;
    int i;
    byte VROM[IMG_WIDTH * IMG_WIDTH / 8];
    FILE *logoImg;
    int byteCount = 0;
    char byteA, byteB, byteC;
    logoImg = fopen(path, "rb");
    fseek(logoImg, 0, SEEK_SET);
    while (!feof(logoImg)) {
        fscanf(logoImg, "%c", &byteA);
        byteCount++;
        if (byteCount == 54)
            break;
    }
    byteCount = 0;
//    char *bitmap;
//    bitmap = (char *)malloc(8 * IMG_WIDTH * IMG_WIDTH);
    int index = IMG_WIDTH * IMG_WIDTH - IMG_WIDTH;
    while (!feof(logoImg)) {
        fscanf(logoImg, "%c", &byteA);
        if (feof(logoImg))
            break;
        fscanf(logoImg, "%c", &byteB);
        if (feof(logoImg))
            break;
        fscanf(logoImg, "%c", &byteC);
        if (feof(logoImg))
            break;
//        byteCount+=3;
//        bitmap[index] = byteA;
        if(byteA == -1)
            SetBitInByteArray(VROM, index, 0);
        else
            SetBitInByteArray(VROM, index, 1);
//        printf("%d ", index);
//        if((index + 1) % 64 == 0)
//            printf("\n");
        index++;
        if (index % IMG_WIDTH == 0)
            index -= 2 * IMG_WIDTH;

    }
//    for (int i = 0; i < IMG_WIDTH * IMG_WIDTH; i++) {
//        if (i % IMG_WIDTH == 0)
//        {
//            printf("\n");
//        }
//        printf("%d", bitmap[i]);
//    }

//    for (int i = 0; i < IMG_WIDTH * IMG_WIDTH / 8; i++) {
//        if (i % 8 == 0)
//        {
//            printf("\n");
//        }
//        printf("%d", VROM[i]);
//    }
    printf("%d\n", byteCount);
//    free(bitmap);
    fclose(logoImg);
    FILE *logoBin;
    logoBin = fopen(resultPath, "wb");
    for(i = 0; i < IMG_WIDTH * IMG_WIDTH / 8; i++)
        fprintf(logoBin, "%c", VROM[i]);
    fclose(logoBin);

}

void ShowBinLogo(char *path, byte *PDP_MEMORY){
    byte VROM[IMG_WIDTH * IMG_WIDTH / 8];
    int i;
    FILE *logoBin;
    logoBin = fopen(path, "rb");
    if(logoBin == NULL)
        printf("NULL");
    for(i = 0; i < IMG_WIDTH * IMG_WIDTH / 8; i++){
        fscanf(logoBin,"%c",&VROM[i]);
    }
    fclose(logoBin);
    bool picBit;
    for(i = 0; i < IMG_WIDTH * IMG_WIDTH; i++){
        picBit = GetBitInByteArray(&PDP_MEMORY[LOGO_START_INDEX], i);
        printf("%d", picBit);
        if((i + 1) % 64 == 0)
            printf("\n");
    }
}





void testingFoo() {
//    byte tW = 0;
//    StartEmulator(PDP_MEMORY);
//    ShowBinLogo("../PDP11_ratite/files/logo.txt", PDP_MEMORY);
//    CreateBinLogo("/Users/carioca/CodingProjects/Qt/PDP11_ratite/logo.bmp", "/Users/carioca/CodingProjects/Qt/PDP11_ratite/logo.txt");
//    FILE *logoImg;
//    logoImg = fopen("/Users/carioca/CodingProjects/Qt/test/logo.bmp", "rb");
//    if(logoImg == NULL)
//        printf("not f\n");
//    else{
//        fclose(logoImg);
//        printf("found\n");
//    }
//    printf("%d\n", tW);
}
