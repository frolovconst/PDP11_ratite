#include <stdio.h>
#include "ratite_body.h"


int main()
{
    Start();
    Step();
    {
        //Test mem out
    //TODO: replace LOGO start index in GetPointerToVRAM foo
    byte *VRAMpointer = GetPointerToVRAM();
    int i;
    bool picBit;
    for(i = 0; i < VRAM_WIDTH * VRAM_WIDTH; i++){
            picBit = (VRAMpointer[i/8] >> (7-i%8))&1;
            printf("%d", picBit);
            if((i + 1) % IMG_WIDTH == 0)
                printf("\n");
        }
    } // end test mem OUT


}



