#include"instructiondecoder.h"
#include<stdio.h>

bool DecodeAndExecute(word IR, byte MEMORY[MEM_SIZE]) {
    byte MSB = getBitInWord(IR, 15);
//    *byteAddressing = getBitInWord(IR, 15);
    byte oct1 = getTriade(IR, 1);
    byte oct2 = getTriade(IR, 2);
    byte oct3 = getTriade(IR,3);//считаем триады слева

    if (!MSB) {                                                 // Most-significant bit
        if (!oct1) {                                            // If single-operand operation
            switch (twoOctal(oct2, oct3)) {
            case INC: //inc();
                break;
            default:
                break;
            }
        }
        else if(oct1 == 7){                                     //register source operand instrucs

            switch (twoOctal(oct1, oct2)) {
            case SOB: //sob();
                break;
            default:
                break;
            }
        }
        else {                                              // Two operand word instructions
            int opSSindex, opDDindex;
            opSSindex = DecodeDoubleInstOperand(IR, 1, MEMORY);
            opDDindex = DecodeDoubleInstOperand(IR, 2, MEMORY);
            switch (oct1) {                         // Octal digit 1
            case 1:
                mov(MEMORY, opSSindex, opDDindex);
                break;
            default:
                break;
            }
        }                           //end oct1 analysis
    }
    return false;
}

int DecodeDoubleInstOperand(word IR, int opNum, byte MEMORY[MEM_SIZE]){
    int opIndex;
    int triadeStartIndex = opNum * 2;
    byte mode = getTriade(IR, triadeStartIndex);
    byte regNum = getTriade(IR, ++triadeStartIndex );
    opIndex = readOperand(mode, regNum, MEMORY);
    return opIndex;
}

int readOperand(byte mode, byte regNumHalf, byte MEMORY[MEM_SIZE]){
    int operandIndex;
    word reg = getWordInByteArray(MEMORY, REG_START_ADDR + 2*regNumHalf);

    switch (mode) {
        case MODE0:
            operandIndex = REG_START_ADDR + 2*regNumHalf;
//            operand = &MEMORY[REG_START_ADDR + 2*regNumHalf];
//            tempIsRegisterOperator = true;
        break;
        case MODE2:
            operandIndex = reg;
//            operand = &MEMORY[reg++];
//            setWordInByteArray(MEMORY, REG_START_ADDR + 2*regNumHalf, reg);
//            registers[regNumHalf]++;
//            tempIsRegisterOperator = false;
        break;
//        case MODE4:    //дальше пока не делал!!!!!!!!!!!!!
//            reg = --registers[regNumHalf];
//            operand = &MEMORY[reg];
//            tempIsRegisterOperator = false;
        break;
//        case MODE6: break;
//        default: printf("Error1");
    }
    return operandIndex;
}
