#include <stdio.h>
//#include "emu_init_funcs.h"
#include "emulatorbody.h"
#include "mem_funcs.h"

word registers[7] = {01,02,03,04,00,00,00};
word IR = 00; // Instruction Register
word operand1 = 00;
word operand2 = 00;
word PC = 0140000;
byte MEMORY[MEM_SIZE];

int main()
{
    printf("Hello World!\n");
    testingFoo();
    testPipeline();


    return 0;
}



