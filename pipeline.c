#include <stdio.h>
#include "emu_init_funcs.h"
#include "mem_funcs.h"
#include "pipeline.h"

void testPipeline() {
    printf("hello pipeline!\n");
    setWord(PC, 010102);
    word w = 054321;

    printRegisters();
    fetch();
    decode();
    printRegisters();
}

void fetch() {
   IR = getWord(PC);
    PC = PC + 2;
}

void decode() {
    if (!getBitInWord(IR, 15)) {
        switch (getTriade(IR, 1)) {
        case 01: doubleReadOperand(); mov(); break;

        }
    }
}

void doubleReadOperand() {
    switch (getTriade(IR, 2)) {  //fetching operand 1
        case 00: operand1 = registers[getTriade(IR,3)]; break;
        default: printf("Error1");
        //return false;
    }
    switch (getTriade(IR, 4)) {
        case 00: operand2 = getTriade(IR,5); break; //determine what register is the destination
        default: printf("Error2");
        //return false;
    }
    //return true;
}

void mov() {
    registers[operand2] = operand2;
}

void execute() {
}




