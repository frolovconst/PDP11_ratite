#ifndef PIPELINE_H
#define PIPELINE_H
#include "emu_init_funcs.h"

void testPipeline();

void fetch();
void decode();
void doubleReadOperand();
void singleReadOperand();
word readOperator(byte, byte);

void mov();
void inc();
void sob();

#endif // PIPELINE_H
