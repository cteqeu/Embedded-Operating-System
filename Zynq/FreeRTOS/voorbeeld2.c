/*
 * voorbeeld2.c
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

#define vPrintString xil_printf

void vTaskFunction( void *pvParameters );

const char *pcTextForTask1 = "Task 1 is running\r\n";
const char *pcTextForTask2 = "Task 2 is running\r\n";

int main(void)
{
	xTaskCreate(vTaskFunction,"Task1",1000,(void*)pcTextForTask1,1,NULL);
	xTaskCreate(vTaskFunction,"Task2",1000,(void*)pcTextForTask2,1,NULL);

	vTaskStartScheduler();

	for(;;);

	return 0;
}

void vTaskFunction(void * pvParameters)
{
	char *pcTaskName;
	volatile uint32_t ul;

	pcTaskName = (char *) pvParameters;
	for(;;)
	{
		vPrintString(pcTaskName);
		for(ul=0;ul<mainDELAY_LOOP_COUNT;ul++)
		{

		}
	}
}
