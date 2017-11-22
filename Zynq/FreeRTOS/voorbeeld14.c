/*
 * voorbeeld14.c
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

#define mainDELAY_LOOP_COUNT		( 0xffffff )

#define vPrintString xil_printf
#define vPrintStringAndNumber xil_printf

#define mainONE_SHOT_TIMER_PERIOD		( pdMS_TO_TICKS( 3333UL ) )
#define mainAUTO_RELOAD_TIMER_PERIOD	( pdMS_TO_TICKS( 500UL ) )

static void prvTimerCallback( TimerHandle_t xTimer );

static TimerHandle_t xAutoReloadTimer, xOneShotTimer;

int main( void )
{
BaseType_t xTimer1Started, xTimer2Started;

	xOneShotTimer = xTimerCreate( "OneShot",
								  mainONE_SHOT_TIMER_PERIOD,
								  pdFALSE,
								  0,
								  prvTimerCallback );

	xAutoReloadTimer = xTimerCreate( "AutoReload",
									 mainAUTO_RELOAD_TIMER_PERIOD,
									 pdTRUE,
									 0,
									 prvTimerCallback );

	if( ( xOneShotTimer != NULL ) && ( xAutoReloadTimer != NULL ) )
	{

		xTimer1Started = xTimerStart( xOneShotTimer, 0 );
		xTimer2Started = xTimerStart( xAutoReloadTimer, 0 );

		if( ( xTimer1Started == pdPASS ) && ( xTimer2Started == pdPASS ) )
		{
			/* Start the scheduler. */
			vTaskStartScheduler();
		}
	}

	for( ;; );
	return 0;
}
/*-----------------------------------------------------------*/

static void prvTimerCallback( TimerHandle_t xTimer )
{
TickType_t xTimeNow;
uint32_t ulExecutionCount;

	ulExecutionCount = ( uint32_t ) pvTimerGetTimerID( xTimer );
	ulExecutionCount++;
	vTimerSetTimerID( xTimer, ( void * ) ulExecutionCount );


	xTimeNow = xTaskGetTickCount();

	if( xTimer == xOneShotTimer )
	{
		vPrintStringAndNumber( "One-shot timer callback executing %d\r\n", xTimeNow );
	}
	else
	{
		vPrintStringAndNumber( "Auto-reload timer callback executing %d\r\n", xTimeNow );

		if( ulExecutionCount == 5 )
		{
			xTimerStop( xTimer, 0 );
		}
	}
}
