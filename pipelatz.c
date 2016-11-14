#include"pipelatz.h"


bool ExecuteNextInstructionSet(byte MEMORY[MEM_SIZE], word *PC){
    word IR;
//    byte opCode;
//    byte operandOne;
//    byte operandTwo;
    while (MEMORY[*PC]) {
            IR = fetch(MEMORY, PC);
            DecodeAndExecute(IR, MEMORY);
        }
    return false;
}

word fetch(byte mem[MEM_SIZE], word *PC) {
   word IR = getWordInByteArray(mem, *PC);
   *PC = *PC + 2;
    return IR;
}



