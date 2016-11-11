#include <stdio.h>
#include "emu_init_funcs.h"
#include "mem_funcs.h"
#include "pipeline.h"

#define SINGLE_OPERAND 0

#define MODE0 00
#define MODE2 02
#define MODE4 04
#define MODE6 06

// page 32 manual
// Mode0 0    REg contains operand
// Mode2 2    Reg contains pointer, then incremented
// Mode4 4    Reg decremented then used as pointer
// Mode6 6    X+Reg = pointer

#define INC 052
#define SOB 077


bool isRegisterOperator1 = false;
bool isRegisterOperator2 = false;

bool tempIsRegisterOperator = false;


void testPipeline() {
    printf("hello pipeline!\n");    // Registers: 01,02,03,04,00,00,00
    setWord(PC, 010102);            // MOVB R2,R3
    setWord(PC+2, 005205);          // INC R6;
    setWord(PC+4, 077402);          // SOB R3,1

    printRegisters();
    while (MEMORY[PC]) {
        fetch();
        decode();
        printRegisters();
    }




}

void fetch() {
   IR = getWord(PC);
   PC = PC + 2;
}

void decode() {
    byte MSB = getBitInWord(IR, 15);
    byte oct1 = getTriade(IR, 1);
    byte oct2 = getTriade(IR, 2);
    byte oct3 = getTriade(IR,3);//считаем триады слева

    if (!MSB) {                                                 // Most-significant bit
        if (!oct1) {                                            // If single-operand operation
            switch (twoOctal(oct2, oct3)) {
            case INC: inc();
                break;
            default:
                break;
            }
        }
        else {
            switch (getTriade(IR, 1)) {                         // Octal digit 1
            case 1: mov(); break;

            }
            switch (twoOctal(oct1, oct2)) {
            case SOB: sob();
                break;
            default:
                break;
            }
        }
    }



}

word readOperator(byte mode, byte regNum) {
    word operand = 0;
    word reg = registers[regNum];

    switch (mode) {
        case MODE0:
            operand = regNum;
            tempIsRegisterOperator = true;
        break;
        case MODE2:
            operand = MEMORY[reg];
            registers[regNum]++;
            tempIsRegisterOperator = false;
        break;
        case MODE4:
            reg = --registers[regNum];
            operand = MEMORY[reg];
            tempIsRegisterOperator = false;
        break;
        case MODE6: break;
        default: printf("Error1");
    }
}

void singleReadOperand() {
    byte mode = getTriade(IR, 4);
    byte regNum = getTriade(IR, 5);
    operand1 = readOperator(mode, regNum);
    isRegisterOperator1 = tempIsRegisterOperator;
}
void doubleReadOperand() {
    byte mode = getTriade(IR, 2);
    byte regNum = getTriade(IR, 3);
    operand1 = readOperator(mode, regNum);
    isRegisterOperator1 = tempIsRegisterOperator;

    mode = getTriade(IR, 4);
    regNum = getTriade(IR, 5);
    operand2 = readOperator(mode, regNum);
    isRegisterOperator2 = tempIsRegisterOperator;

}



void execute() {
}




