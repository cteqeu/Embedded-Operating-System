/*
 * voorbeeld15.c
 *
 *  Created on: 7 nov. 2017
 *      Author: Vincent Claes
 *      e-mail: vincent.claes[at]pxl.be
 */


#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#include "xil_printf.h"
#include "xparameters.h"

#include <stdio.h>

#define mainDELAY_LOOP_COUNT		( 0xffffff )

#define vPrintString xil_printf
#define vPrintStringAndNumber xil_printf

#define mainBACKLIGHT_TIMER_PERIOD		( pdMS_TO_TICKS( 5000UL ) )


static void prvBacklightTimerCallback( TimerHandle_t xTimer );

static void vKeyHitTask( void *pvParameters );


static BaseType_t xSimulatedBacklightOn = pdFALSE;

static TimerHandle_t xBacklightTimer = NULL;

/*-----------------------------------------------------------*/

int main( void )
{
	xSimulatedBacklightOn = pdFALSE;

	xBacklightTimer = xTimerCreate( "Backlight",
									mainBACKLIGHT_TIMER_PERIOD,
									pdFALSE,
									0,
									prvBacklightTimerCallback );
	xTaskCreate( vKeyHitTask, "Key poll", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );

	xTimerStart( xBacklightTimer, 0 );

	vTaskStartScheduler();

	for( ;; );
	return 0;
}
/*-----------------------------------------------------------*/

static void prvBacklightTimerCallback( TimerHandle_t xTimer )
{
TickType_t xTimeNow = xTaskGetTickCount();

	xSimulatedBacklightOn = pdFALSE;

	vPrintStringAndNumber( "Timer expired, turning backlight OFF at time\t %d\r\n", xTimeNow );
}
/*-----------------------------------------------------------*/

static void vKeyHitTask( void *pvParameters )
{
const TickType_t xShortDelay = pdMS_TO_TICKS( 50 );
TickType_t xTimeNow;

	vPrintString( "Press a key to turn the backlight on.\r\n" );

	for( ;; )
	{
		if( getchar() != 0 )
		{

			xTimeNow = xTaskGetTickCount();


			if( xSimulatedBacklightOn == pdFALSE )
			{

				xSimulatedBacklightOn = pdTRUE;
				vPrintStringAndNumber( "Key pressed, turning backlight ON at time\t %d\r\n", xTimeNow );
			}
			else
			{

				vPrintStringAndNumber( "Key pressed, resetting software timer at time\t %d\r\n", xTimeNow );
			}

			xTimerReset( xBacklightTimer, xShortDelay );

			( void ) getchar();
		}

		vTaskDelay( xShortDelay );
	}
}
