#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/*****************************
* Private types/enumerations/variables
/*****************************

/*****************************
* Public types/enumerations/variables
*****************************

/*****************************
* Private functions
*****************************

/* Sets up system hardware */
static void prvSetupHardware(void)
{
 SystemCoreClockUpdate();
 Board_Init();

 /* Defining the Values of LEDs, i.e false will blink the LEDs and true will turn off the LEDs*/
 Board_LED_Set(0, false);
 Board_LED_Set(0, true);
 Board_LED_Set(1, false);
 Board_LED_Set(1, true);
 Board_LED_Set(2, false);
 Board_LED_Set(2, true);
}
/*creating Binary semaphore*/
xSemaphoreHandle LEDSync = 0;

/* Blinking LED1 */
static void vLEDTask1(void *pvParameters)
{
 while (1)
{

 xSemaphoreTake(LEDSync,portMAX_
 Board_LED_Set(0, false);
 vTaskDelay(configTICK_RATE_HZ / 2.3);
 Board_LED_Set(0, true);
 xSemaphoreGive(LEDSync);

  }
}

/* Blinking LED2 */
static void vLEDTask2(void *pvParameters)
 {

 while (1)
 {

 xSemaphoreTake(LEDSync,portMAX_
 Board_LED_Set(1, false);
 vTaskDelay(configTICK_RATE_HZ / 2.3);
 Board_LED_Set(1, true);
 xSemaphoreGive(LEDSync);

 }
}

/* Blinking LED 3 */
static void vLEDTask3(void *pvParameters)
{

 while (1)
 {

 xSemaphoreTake(LEDSync,portMAX_
 Board_LED_Set(2,false);
 vTaskDelay(configTICK_RATE_HZ / 2.3);
 Board_LED_Set(2,true);
 xSemaphoreGive(LEDSync);

 }
}

/*****************************
* Public functions
*****************************

**
* @brief main routine for FreeRTOS blinky example
* @return Nothing, function should not exit
*/
int main(void)
{
 LEDSync = xSemaphoreCreateLEDSync();
 prvSetupHardware();

/*setting priority level for each task*/
 /* LED1 toggle thread */
 xTaskCreate(vLEDTask1, (signed char *) "vTaskLed1",
             configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
 (xTaskHandle *) NULL);

 /* LED2 toggle thread */
 xTaskCreate(vLEDTask2, (signed char *) "vTaskLed2",
 configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
 (xTaskHandle *) NULL);

 /* LED3 toggle thread */
 xTaskCreate(vLEDTask3, (signed char *) "vTaskLed2",
 configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
 (xTaskHandle *) NULL);


 /* Start the scheduler */
 vTaskStartScheduler();

 /* Should never arrive here */
 return 1;
}




/*
* @brief FreeRTOS Blinky example
*
* @note
* Copyright(C) NXP Semiconductors, 2014
* All rights reserved.
*
* @par
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* LPC products. This software is supplied "AS IS" without any warranties of
* any kind, and NXP Semiconductors and its licensor disclaim any and
* all warranties, express or implied, including all implied warranties of
* merchantability, fitness for a particular purpose and non-infringement of
* intellectual property rights. NXP Semiconductors assumes no responsibility
* or liability for the use of the software, conveys no license or rights under any
* patent, copyright, mask work right, or any other intellectual property rights in
* or to any products. NXP Semiconductors reserves the right to make changes
* in the software without notification. NXP Semiconductors also makes no
* representation or warranty that such application will be suitable for the
* specified use without further testing or modification.
*
* @par
* Permission to use, copy, modify, and distribute this software and its
* documentation is hereby granted, under NXP Semiconductors' and its
* licensor's relevant copyrights in the software, without fee, provided that it
* is used in conjunction with NXP Semiconductors microcontrollers.  This
* copyright, permission, and disclaimer notice must appear in all copies of
* this code.
*/
/**
* @}
*/
