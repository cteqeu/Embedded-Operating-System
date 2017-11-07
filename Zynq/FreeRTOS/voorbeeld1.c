/*
 * voorbeeld1.c
 *
 *  Created on: 7 nov. 2017
 *      Author: Vincent Claes
 *      e-mail: vincent.claes[at]pxl.be
 */


#include "FreeRTOS.h"
#include "task.h"

#include "xil_printf.h"
#include "xparameters.h"

#define mainDELAY_LOOP_COUNT		( 0xffffff )

void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

#define vPrintString xil_printf

int main(void)
{
	xTaskCreate(vTask1,"Task1",1000,NULL,1,NULL);
	xTaskCreate(vTask2,"Task2",1000,NULL,1,NULL);

	vTaskStartScheduler();

	for(;;);

	return 0;
}

void vTask1(void *pvParameters)
{
	const char *pcTaskName = "Task 1 is running\r\n";
	volatile uint32_t ul;

	for(;;)
	{
		vPrintString(pcTaskName);
		for(ul=0;ul< mainDELAY_LOOP_COUNT;ul++)
		{

		}
	}
}

void vTask2(void *pvParameters)
{
	const char *pcTaskName = "Task 2 is running\r\n";
	volatile uint32_t ul;

	for(;;)
	{
		vPrintString(pcTaskName);
		for(ul=0;ul< mainDELAY_LOOP_COUNT;ul++)
		{

		}
	}
}


