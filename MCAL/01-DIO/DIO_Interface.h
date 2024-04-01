/**
 * @file DIO_Interface.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  Digital Input Output (DIO) driver for Atmega32 microcontroller.
 * 		   This file contains the declaration of the DIO driver functions.
 * 		   The DIO driver provides functions to initialize pins, set pin direction, set pin value, and read pin value.
 * 		   The driver supports the Atmega32 microcontroller.
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  TYPEDEFS                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/

typedef enum{
	PA,
	PB,
	PC,
	PD
} DIO_PORT_t;

typedef enum{
	PA0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,

	PC0,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,
	
	PD0,
	PD1,
	PD2,
	PD3,
	PD4,
	PD5,
	PD6,
	PD7,
	DIO_TOTAL_PINS
} DIO_PIN_t;

typedef enum{
	DIO_PIN_DIRECTION_OUTPUT,
	DIO_PIN_DIRECTION_INPUT_FREE,
	DIO_PIN_DIRECTION_INPUT_PULLUP
} DIO_PIN_DIRECTION_t;

typedef enum{
	DIO_VOLT_LOW,
	DIO_VOLT_HIGH
	} DIO_VOLTAGE_LEVEL_t;

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                             API FUNCTIONS                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/

/**
 * @brief Initializes the Digital I/O (DIO) pins.
 * 
 * This function initializes the DIO pins by setting their directions based on the values
 * in the 'arrOfPinsStatus' array which is located in DIO_lcfg.c.
 * 
 * @param None
 * @return None
 */
void Dio_Init(void);

/**
 * @brief Reads the voltage level of a specific pin.
 *
 * This function reads the voltage level of the specified pin.
 *
 * @param pin The pin number to read the voltage level from.
 * @return The voltage level of the pin (DIO_VOLT_HIGH or DIO_VOLT_LOW).
 */
DIO_VOLTAGE_LEVEL_t Dio_ReadPin(const DIO_PIN_t pin);


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
void Dio_WritePin(const DIO_PIN_t pin, const DIO_VOLTAGE_LEVEL_t volt);

/**
 * @brief Toggles the voltage level of a specific pin.
 *
 * This function toggles the voltage level of a specific pin in the microcontroller's GPIO ports.
 *
 * @param pin The pin number to toggle its voltage level.
 *
 * @return None.
 */
void Dio_TogglePin(const DIO_PIN_t pin);

/**
 * @brief Writes a value to the specified port.
 *
 * This function writes the given value to the specified port.
 *
 * @param port The port to write to. It should be one of the values from the DIO_PORT_t enumeration.
 * @param value The value to write to the port.
 */
void Dio_WritePort(const DIO_PORT_t port, const u8 value);

void Dio_WritePortMaskedValue(const DIO_PORT_t port,const u8 mask ,const u8 value);

/**
 * @brief Reads the voltage level of a specific port.
 *
 * This function reads the voltage level of the specified port.
 *
 * @param port The port number to read the voltage level from.
 * @return The voltage level of the port.
 */
u8 Dio_ReadPort(const DIO_PORT_t port);

/**
 * @brief Toggles the voltage level of a specific port.
 *
 * This function toggles the voltage level of a specific port in the microcontroller's GPIO ports.
 *
 * @param port The port number to toggle its voltage level.
 *
 * @return None.
 */
void Dio_TogglePort(const DIO_PORT_t port);

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                             END OF FILE                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/




#endif /* DIO_INTERFACE_H_ */