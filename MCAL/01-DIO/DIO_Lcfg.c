/**
 * @file DIO_Lcfg.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief 	This file contains the configuration of the DIO driver.
 * 			The configuration includes the initial direction of the pins.
 * 			The configuration is an array of DIO_PIN_DIRECTION_t that contains the initial direction of the pins.
 * 			The array is used to initialize the pins in the Dio_Init function.
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Std_Types.h"
#include "DIO_Interface.h"


/**
 * @brief Array of the initial direction of the pins.
 * 
 * This array contains the initial direction of the pins.
 * The array is used to initialize the pins in the Dio_Init function.
 * The array is an array of DIO_PIN_DIRECTION_t that contains the initial direction of the pins.
 * The array is indexed by the pin number.
 * The array is used to initialize the pins in the Dio_Init function.
 * OPTIONS:
 * - DIO_PIN_DIRECTION_OUTPUT: Sets the pin as output.
 * - DIO_PIN_DIRECTION_INPUT_FREE: Sets the pin as input with high impedance (free).
 * - DIO_PIN_DIRECTION_INPUT_PULLUP: Sets the pin as input with pull-up resistor.
 */
const DIO_PIN_DIRECTION_t arrOfPinsStatus[DIO_TOTAL_PINS]={
	DIO_PIN_DIRECTION_OUTPUT,          /* PA0 (ADC0) */
	DIO_PIN_DIRECTION_OUTPUT,          /* PA1 (ADC1) */
	DIO_PIN_DIRECTION_OUTPUT,          /* PA2 (ADC2) */
	DIO_PIN_DIRECTION_OUTPUT,          /* PA3 (ADC3) */
	DIO_PIN_DIRECTION_OUTPUT,          /* PA4 (ADC4) */
	DIO_PIN_DIRECTION_OUTPUT,          /* PA5 (ADC5) */
	DIO_PIN_DIRECTION_OUTPUT,          /* PA6 (ADC6) */
	DIO_PIN_DIRECTION_OUTPUT,          /* PA7 (ADC7) */	
	
	DIO_PIN_DIRECTION_OUTPUT,          /* PB0  (XCK/T0)    */	
	DIO_PIN_DIRECTION_OUTPUT,          /* PB1  (T1) 	   */
	DIO_PIN_DIRECTION_OUTPUT,          /* PB2  (INT2/AIN0) */  
	DIO_PIN_DIRECTION_OUTPUT,          /* PB3  (OC0/AIN1)  */	
	DIO_PIN_DIRECTION_INPUT_PULLUP,    /* PB4  (SS)        */	
	DIO_PIN_DIRECTION_OUTPUT,          /* PB5  (MOSI)      */	
	DIO_PIN_DIRECTION_OUTPUT,          /* PB6  (MISO)      */	
	DIO_PIN_DIRECTION_OUTPUT,          /* PB7  (SCK)       */	
	
	DIO_PIN_DIRECTION_OUTPUT,          /* PC0 (SCL)	 */	 
	DIO_PIN_DIRECTION_OUTPUT,          /* PC1 (SDA)	 */	
	DIO_PIN_DIRECTION_OUTPUT,          /* PC2 (TCK)	 */	
	DIO_PIN_DIRECTION_OUTPUT,          /* PC3 (TMS)	 */	
	DIO_PIN_DIRECTION_OUTPUT,          /* PC4 (TDO)	 */	
	DIO_PIN_DIRECTION_OUTPUT,          /* PC5 (TDI)	 */	
	DIO_PIN_DIRECTION_OUTPUT,          /* PC6 (TOSC1)*/	
	DIO_PIN_DIRECTION_OUTPUT,          /* PC7 (TOSC2)*/	
	
	DIO_PIN_DIRECTION_OUTPUT,          /* PD0 (RXD)  */
	DIO_PIN_DIRECTION_OUTPUT,          /* PD1 (TXD)  */
	
	DIO_PIN_DIRECTION_INPUT_PULLUP,    /* PD2 (INT0) */
	
	DIO_PIN_DIRECTION_OUTPUT,          /* PD3 (INT1) */
	DIO_PIN_DIRECTION_OUTPUT,          /* PD4 (OC1B) */
	DIO_PIN_DIRECTION_OUTPUT,          /* PD5 (OC1A) */
	DIO_PIN_DIRECTION_OUTPUT,          /* PD6 (ICP)  */
	DIO_PIN_DIRECTION_INPUT_PULLUP     /* PD7 (OC2)  */	
	};