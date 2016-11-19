#include"pipelatz.h"


bool ExecuteNextInstructionSet(byte MEMORY[MEM_SIZE]){
    word IR;
    word PC = getWordInByteArray(MEMORY, PC_INDX);
    while (MEMORY[PC]) {
            IR = fetch(MEMORY);
            DecodeAndExecute(IR, MEMORY);
            PC = getWordInByteArray(MEMORY, PC_INDX);
        }
    return false;
}

word fetch(byte mem[MEM_SIZE]) {
   word PC = getWordInByteArray(mem, PC_INDX);
   word IR = getWordInByteArray(mem, PC);
   setWordInByteArray(mem, PC_INDX, PC + 2);
   return IR;
}




