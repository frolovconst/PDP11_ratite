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
    for(i = 0; i < IMG_WIDTH * IMG_WIDTH; i++){
            picBit = (VRAMpointer[i/8] >> (7-i%8))&1;
            printf("%d", picBit);
            if((i + 1) % 64 == 0)
                printf("\n");
        }
    } // end test mem OUT


    Start();
    Step();


}



