#include "pipeline.h"
#include "mem_funcs.h"


void mov() {
    doubleReadOperand();
    if (isRegisterOperator2) {
        if (isRegisterOperator1) {
            registers[operand2] = registers[operand1];
        }
        else registers[operand2] = MEMORY[operand2];
    }
    else {
        if (isRegisterOperator1) {
            MEMORY[operand2] = operand1;
        }
        else MEMORY[operand2] = MEMORY[operand1];
    }
}

void inc() {
    singleReadOperand();
    if (isRegisterOperator1) {
        registers[operand1]++;
    }
    else MEMORY[operand1]++;
}

void sob() {
    word regNum = getTriade(IR, 3);
    byte offset = twoOctal(getTriade(IR,4),getTriade(IR,5));
    if (--registers[regNum]) {
        PC -= 2 * offset;
    }
}
