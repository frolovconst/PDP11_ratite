#ifndef EMUINITFUNCS_H
#define EMUINITFUNCS_H
#include<stdint.h>
#include<stdbool.h>
#include<math.h>

#define IMG_WIDTH 64
#define MEM_SIZE 65544
#define RAM_START_INDEX 0
#define VRAM_START_INDEX 16384
#define ROM_START_INDEX 49152
#define LOGO_START_INDEX 56832
#define IO_START_INDEX

typedef uint8_t byte;  // 1
typedef uint16_t word;  // 1

 word registers[7];
 word IR;
 word operand1;
 word operand2;
 bool isRegisterOperator1;
 bool isRegisterOperator2;

 word PC;
 byte MEMORY[MEM_SIZE];

void SetBitInByte(byte *, int, bool);       // 1
void SetBitInByteArray(byte *, int, bool);  // 1
void testingFoo();
bool CopyLogoToROM(const char *logoPath, byte mem[MEM_SIZE]);
bool ResetVRAM(byte [MEM_SIZE]);
bool ResetMEM(byte mem[MEM_SIZE]);
bool GetBitInByteArray(byte *array, int index);
bool InitializePC(byte mem[MEM_SIZE]);

#endif // EMUINITFUNCS_H
