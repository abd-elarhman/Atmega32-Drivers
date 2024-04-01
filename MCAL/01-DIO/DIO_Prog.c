/**
 * @file DIO_Prog.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief 	Digital Input Output (DIO) driver for Atmega32 microcontroller.
 * 			This file contains the implementation of the DIO driver functions.
 * 			The DIO driver provides functions to initialize pins, set pin direction, set pin value, and read pin value.
 * 			The driver supports the Atmega32 microcontroller.
 * @version 0.1
 * @date 2024-03-10
 * 
 * @see DIO_Interface.h
 * @see DIO_Private.h
 * @see DIO_Cfg.h
 * @see DIO_Lcfg.c
 * @copyright Copyright (c) 2024
 * 
 */
#include "Std_Types.h"
#include "MemMap.h"
#include "Utils_BitMath.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PRIVATE Functions                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Sets the direction of a specific pin in the DIO module.
 *
 * This function sets the direction of a specific pin in the DIO module to either output, input with
 * high impedance (free), or input with pull-up resistor enabled.
 *
 * @param pin The pin number to set its direction.
 * @param direction The desired direction for the pin.
 *        - DIO_PIN_DIRECTION_OUTPUT: Sets the pin as output.
 *        - DIO_PIN_DIRECTION_INPUT_FREE: Sets the pin as input with high impedance (free).
 *        - DIO_PIN_DIRECTION_INPUT_PULLUP: Sets the pin as input with pull-up resistor enabled.
 */
static void Dio_SetPinDirection(const DIO_PIN_t pin,const DIO_PIN_DIRECTION_t direction)
{
	volatile u8 *arrOf_DDR[]={&DDRA,&DDRB,&DDRC,&DDRD}; // Array of DDR registers for each port
	volatile u8 *arrOf_PORT[]={&PORTA,&PORTB,&PORTC,&PORTD}; // Array of PORT registers for each port
	
	switch(direction)
	{
		case DIO_PIN_DIRECTION_OUTPUT:
			set_bit(*arrOf_DDR[pin/8], pin%8);    // Set the pin as output
			clear_bit(*arrOf_PORT[pin/8],pin%8);   // Set the pin voltage to LOW
			break;
		
		case DIO_PIN_DIRECTION_INPUT_FREE:
			clear_bit(*arrOf_DDR[pin/8], pin%8);    // Set the pin as input
			clear_bit(*arrOf_PORT[pin/8],pin%8);   // Set the input as INFREE
			break;
		
		case DIO_PIN_DIRECTION_INPUT_PULLUP:
			clear_bit(*arrOf_DDR[pin/8], pin%8);    // Set the pin as input
			set_bit(*arrOf_PORT[pin/8],pin%8);   // Set the input as INPULLUP
			break;
	}
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PUPLIC Functions                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/



/**
 * @brief Initializes the Digital I/O (DIO) pins.
 * 
 * This function initializes the DIO pins by setting their directions based on the values
 * in the 'arrOfPinsStatus' array which is located in DIO_lcfg.c.
 * 
 * @param None
 * @return None
 */
void Dio_Init(void)
{
	DIO_PIN_t i;
	for (i = PA0; i < DIO_TOTAL_PINS; i++)
	{
		Dio_SetPinDirection(i, arrOfPinsStatus[i]);
	}
}

/**
 * @brief Reads the voltage level of a specific pin.
 *
 * This function reads the voltage level of the specified pin.
 *
 * @param pin The pin number to read the voltage level from.
 * @return The voltage level of the pin (DIO_VOLT_HIGH or DIO_VOLT_LOW).
 */
DIO_VOLTAGE_LEVEL_t Dio_ReadPin(const DIO_PIN_t pin)
{
	volatile u8 *arrOf_PIN[] = {&PINA, &PINB, &PINC, &PIND}; /**< Array of PIN registers for each port */
	DIO_VOLTAGE_LEVEL_t voltage = DIO_VOLT_LOW; /**< Initialize voltage variable with DIO_VOLT_LOW */
	voltage = get_bit(*arrOf_PIN[pin / 8], pin % 8); /**< Read the voltage level of the specified pin */
	return voltage; /**< Return the voltage level of the pin */
}


/**
 * @brief Sets the voltage level of a specific pin.
 *
 * This function sets the voltage level of a specific pin in the microcontroller's GPIO ports.
 *
 * @param pin The pin number to set its voltage level.
 * @param volt The voltage level to be set (HIGH or LOW).
 *
 * @return None.
 */
void Dio_WritePin(const DIO_PIN_t pin, const DIO_VOLTAGE_LEVEL_t volt)
{
	volatile u8 *arrOf_PORT[]={&PORTA,&PORTB,&PORTC,&PORTD};
	write_bit(*arrOf_PORT[pin/8],pin%8,volt); /**< Set the voltage level of the specified pin */
}

/**
 * @brief Toggles the voltage level of a specific pin.
 *
 * This function toggles the voltage level of a specific pin in the microcontroller's GPIO ports.
 *
 * @param pin The pin number to toggle its voltage level.
 *
 * @return None.
 */
void Dio_TogglePin(const DIO_PIN_t pin)
{
	volatile u8 *arrOf_PORT[]={&PORTA,&PORTB,&PORTC,&PORTD};
	toggle_bit(*arrOf_PORT[pin/8],pin%8);
}


/**
 * @brief Writes a value to the specified port.
 *
 * This function writes the given value to the specified port.
 *
 * @param port The port to write to. It should be one of the values from the DIO_PORT_t enumeration.
 * @param value The value to write to the port.
 */
void Dio_WritePort(const DIO_PORT_t port, const u8 value)
{
	volatile u8 *arrOf_PORT[]={&PORTA,&PORTB,&PORTC,&PORTD};
	*arrOf_PORT[port] = value;
}

void Dio_WritePortMaskedValue(const DIO_PORT_t port,const u8 mask ,const u8 value)
{
	volatile u8 *arrOf_PORT[]={&PORTA,&PORTB,&PORTC,&PORTD};
	write_masked_value(*arrOf_PORT[port],mask,value);
}

/**
 * @brief Reads the voltage level of a specific port.
 *
 * This function reads the voltage level of the specified port.
 *
 * @param port The port number to read the voltage level from.
 * @return The voltage level of the port.
 */
u8 Dio_ReadPort(const DIO_PORT_t port)
{
	volatile u8 *arrOf_PIN[]={&PINA,&PINB,&PINC,&PIND};
	return *arrOf_PIN[port];
}

/**
 * @brief Toggles the voltage level of a specific port.
 *
 * This function toggles the voltage level of a specific port in the microcontroller's GPIO ports.
 *
 * @param port The port number to toggle its voltage level.
 *
 * @return None.
 */
void Dio_TogglePort(const DIO_PORT_t port)
{
	volatile u8 *arrOf_PORT[]={&PORTA,&PORTB,&PORTC,&PORTD};
	*arrOf_PORT[port] ^= 0xFF;
}



























































































































