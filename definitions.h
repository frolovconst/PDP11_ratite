#include<stdint.h>
#include<stdbool.h>

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef uint8_t byte;
typedef uint16_t word;

#define IMG_WIDTH 64
#define MEM_SIZE 65552
#define RAM_START_INDEX 0
#define VRAM_START_INDEX 16384
#define ROM_START_INDEX 49152
#define LOGO_START_INDEX 56832
#define IO_START_INDEX 0160000
#define REG_START_ADDR 65536

#endif // DEFINITIONS_H
