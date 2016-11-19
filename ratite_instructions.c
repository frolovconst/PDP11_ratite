#include"ratite_instructions.h"
//#include<stdio.h>

bool mov(byte MEMORY[MEM_SIZE], int opSSindex, int opDDindex) {
    word SS = getWordInByteArray(MEMORY, opSSindex);
    setWordInByteArray(MEMORY, opDDindex, SS);
    return false;

//    doubleReadOperand();
//    if (isRegisterOperator2) {
//        if (isRegisterOperator1) {
//            registers[operand2] = registers[operand1];
//        }
//        else registers[operand2] = MEMORY[operand2];
//    }
//    else {
//        if (isRegisterOperator1) {
//            MEMORY[operand2] = operand1;
//        }
//        else MEMORY[operand2] = MEMORY[operand1];
//    }
}

bool sob(byte MEMORY[MEM_SIZE], byte halfRegNum, byte offset){
    word regValue = getWordInByteArray(MEMORY, REG_START_ADDR + halfRegNum * 2) - 1;
    setWordInByteArray(MEMORY, REG_START_ADDR + halfRegNum * 2, regValue);
    if (regValue) {
        word PC = getWordInByteArray(MEMORY, PC_INDX);
        PC -= 2 * offset;
        setWordInByteArray(MEMORY, PC_INDX, PC);
    }
    return false;
}

bool add(byte MEMORY[MEM_SIZE], int opSSindex, int opDDindex){
    word SS = getWordInByteArray(MEMORY, opSSindex);
    word DD = getWordInByteArray(MEMORY, opDDindex);
    setWordInByteArray(MEMORY, opDDindex, DD + SS);
    return false;
}
