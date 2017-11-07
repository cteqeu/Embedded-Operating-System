/*
 * voorbeeld6.c
 *
 *  Created on: 7 nov. 2017
 *      Author: Vincent Claes
 *      e-mail: vincent.claes[at]pxl.be
 */


#include "FreeRTOS.h"
#include "task.h"

#include "xil_printf.h"
#include "xparameters.h"

#define vPrintString xil_printf

void vContinuousProcessingTask( void *pvParameters );
void vPeriodicTask( void *pvParameters );

const char *pcTextForTask1 = "Task 1 is running\r\n";
const char *pcTextForTask2 = "Task 2 is running\r\n";
const char *pcTextForPeriodicTask = "Periodic task is running\r\n";

int main(void)
{
	xTaskCreate(vContinuousProcessingTask,"Task1",1000,(void*)pcTextForTask1,1,NULL);
	xTaskCreate(vContinuousProcessingTask,"Task2",1000,(void*)pcTextForTask2,1,NULL);

	xTaskCreate( vPeriodicTask, "Task 3", 1000, (void*)pcTextForPeriodicTask, 2, NULL );

	vTaskStartScheduler();

	for(;;);

	return 0;
}

void vPeriodicTask(void * pvParameters)
{
	TickType_t xLastWakeTime;
	const TickType_t xDelay50ms = pdMS_TO_TICKS(50);

	xLastWakeTime = xTaskGetTickCount();

	for(;;)
	{
		vPrintString("Periodic task is running\r\n");
		vTaskDelayUntil(&xLastWakeTime, xDelay50ms);
	}
}

void vContinuousProcessingTask(void * pvParameters)
{
	char *pcTaskName;

	pcTaskName = (char *) pvParameters;

	for(;;)
	{
		vPrintString(pcTaskName);
	}
}
