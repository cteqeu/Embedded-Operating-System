/*
 * main.c
 *
 *  Created on: 20-feb.-2017
 *      Author: Vincent Claes
 */


#include "lcd8x8rgb.h"

u8 h[]="Hogeschool PXL RGB Matrix  by Vincent Claes";
bool point = 1;

int main()
{
	//XSpiPs_Config *SpiConfig;
	//u16 SpiDeviceId= SPI_DEVICE_ID;
	//XSpiPs *SpiInstancePtr;

    init_platform();
    print("Demo Application by Vincent Claes\n\r");
    InitMatrix();
    while(1)
    {
    	/*point=!point;
    	scrollString(h,point);
    	Transfer();
    	delay(100);
    	vClear();*/

    	drawPixel(2,3);
    	Transfer();
    	delay(100);
    }

    cleanup_platform();
    return 0;
}


