#include"ratite_mem_funcs.h"


bool GetBitInByte(byte inByte, int index) { // Index 0 starts from the right
    return (inByte >> index) & 1;
}

bool GetBitInByteArray(byte *array, int index){ // Needs fixing!!! Do not use!
    int byteIndex = index / 8;
    int bitIndex = index % 8;
    return GetBitInByte(array[byteIndex], bitIndex);
}

bool getBitInWord(word inByte, int index) { // Index 0 starts from the right
    return (bool) ((inByte >> index) & 1);
}

byte getTriade(word inWord, int index) { //gives octal digit. Index 0 starts from left triade.
    return ((inWord >> ( 15 - 3 * index)) & 7);
}

word getWordInByteArray(byte *array, int address) {
    word _word = 0;
    _word += array[address];
    _word += (array[address+1]<<8);
    return _word;
}

byte twoOctal(byte bOne, byte bTwo) {               // WTF?????
    return ((word)bOne * 8) + ((word) bTwo);
}

void setWordInByteArray(byte *array, int address, word _word) {
    array[address] = _word & 255;
    array[++address] = _word >> 8;
}

void SetBitInByteArray(byte *array, int index, bool value){  // Needs fixing!!! Do not use!
    int byteIndex = index / 8;
    int bitIndex = index % 8;
    SetBitInByte(&array[byteIndex], bitIndex, value);
}

void SetBitInByte(byte *inByte, int index, bool value) {
    if (value) {
//        byte aux = 1 << (7 - index);
        byte aux = 1 << index;
        *inByte = (*inByte) | aux;
    }
    else {
        byte aux = 255 - pow(2,7-index);
        *inByte = (*inByte) & aux;
    }
}
