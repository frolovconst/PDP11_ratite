#ifndef EMUINITFUNCS_H
#define EMUINITFUNCS_H
#include<stdint.h>
#include<stdbool.h>
#include<math.h>

#define IMG_WIDTH 64
#define MEM_SIZE 65552
#define RAM_START_INDEX 0
#define VRAM_START_INDEX 16384
#define ROM_START_INDEX 49152
#define LOGO_START_INDEX 56832
#define IO_START_INDEX 57344

typedef uint8_t byte;
typedef uint16_t word;

void SetBitInByte(byte *, int, bool);
void SetBitInByteArray(byte *, int, bool);
void testingFoo();
bool CopyLogoToROM(const char *logoPath, byte mem[MEM_SIZE]);
bool ResetVRAM(byte [MEM_SIZE]);
bool ResetMEM(byte mem[MEM_SIZE]);
bool GetBitInByteArray(byte *array, int index);


#endif // EMUINITFUNCS_H
