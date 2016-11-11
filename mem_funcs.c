#include "mem_funcs.h"
#include<stdio.h>

void printRegisters() {
    registers[6] = PC;
    for (int i=0; i<=6; i++) {
        printf("R%d = %o ",i+1,registers[i]);
    }
    printf("\n");
    //printf("op1 %d op2 %d\n",operand1,operand2);
}

bool getBitInWord(word inByte, int index) {
    return (bool) ((inByte >> index) & 1);
}

byte getTriade(word inByte, int index) { //gives octal digit. Index 0 starts from left triade.
    return ((inByte >> ( 15 - 3 * index)) & 7);
}

byte twoOctal(byte bOne, byte bTwo) {
    return ((word)bOne * 8) + ((word) bTwo);
}

void setWord(int address, word _word) {
    MEMORY[address] = _word & 255;
    MEMORY[++address] = _word >> 8;
}

word getWord(int address) {
    word _word = 0;
    _word += MEMORY[address];
    _word += (MEMORY[address+1]<<8);
    return _word;
}
