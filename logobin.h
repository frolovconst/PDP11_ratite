#include<stdlib.h>
#ifndef LOGOBIN_H
#define LOGOBIN_H
#include<stdint.h>
#include<stdbool.h>
#include<math.h>

typedef uint8_t byte;
typedef uint16_t word;

void SetBitInByte(byte *, int, bool);
void SetBitInByteArray(byte *, int, bool);
void testingFoo();


#endif // LOGOBIN_H
