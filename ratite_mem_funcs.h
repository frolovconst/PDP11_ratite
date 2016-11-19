#include"definitions.h"
#include<math.h>



#ifndef RATITE_MEM_FUNCS_H
#define RATITE_MEM_FUNCS_H

bool GetBitInByte(byte , int ) ;
bool GetBitInByteArray(byte *, int );
bool getBitInWord(word , int ) ;
byte getTriade(word , int ) ;
word getWordInByteArray(byte *, int ) ;
byte twoOctal(byte , byte ) ;
void setWordInByteArray(byte *, int , word ) ;
void SetBitInByteArray(byte *, int , bool );
void SetBitInByte(byte *, int , bool ) ;

#endif // RATITE_MEM_FUNCS_H
