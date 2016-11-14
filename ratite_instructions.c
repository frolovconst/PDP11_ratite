#include"ratite_instructions.h"
//#include<stdio.h>

bool mov(byte MEMORY[MEM_SIZE], int opSSindex, int opDDindex) {
//    printf("%d %d\n", opSSindex, opDDindex);
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
