/*
 * voorbeeld9.c
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

void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

TaskHandle_t xTask2Handle;

int main( void )
{

	xTaskCreate( vTask1, "Task 1", 1000, NULL, 1, NULL );

	vTaskStartScheduler();

	for( ;; );
	return 0;
}

void vTask1( void *pvParameters )
{
const TickType_t xDelay100ms = pdMS_TO_TICKS( 100UL );

	for( ;; )
	{
		vPrintString( "Task1 is running\r\n" );

		xTaskCreate( vTask2, "Task 2", 1000, NULL, 2, &xTask2Handle );

		vTaskDelay( xDelay100ms );
	}
}

/*-----------------------------------------------------------*/

void vTask2( void *pvParameters )
{

	vPrintString( "Task2 is running and about to delete itself\r\n" );
	vTaskDelete( xTask2Handle );
}
