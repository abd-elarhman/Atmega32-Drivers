/**
 * @file UART_private.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file contains the private information of UART module in the microcontroller.
 *         The file contains the private functions of the UART module.
 *         The user must not include this file in the application code.
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PRIVATE Macros                                 */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
#define DATA_REG_EMPTY  1
#define TX_COMPLETE     1
#define RX_COMPLETE     1

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                          Static Global Vaiables                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/

/*
*  Global pointer to function to hold the address of the call back function
*/
/**
 * @brief Pointer to function for UART TX Complete callback.
 *        This function is called when the UART transmission is complete.
 *        It is used to handle any necessary actions after the transmission is finished.
 */
static void (*pfCallBackUartTXC)(void) = NULL_PTR;

/**
 * @brief Pointer to function for UART RX Complete callback.
 *        This function is called when the UART reception is complete.
 *        It is used to handle any necessary actions after the reception is finished.
 */
static void (*pfCallBackUartRXC)(void) = NULL_PTR;

/**
 * @brief Pointer to function for UART Data Register Empty callback.
 *        This function is called when the UART data register is empty and ready to transmit new data.
 *        It is used to handle any necessary actions before transmitting new data.
 */
static void (*pfCallBackUartUDRE)(void) = NULL_PTR;

// Array to store the baud rate values for different speed modes, CPU frequencies, and baud rates
static const u16 BaudRateArray[TOTAL_SPEED_MODE][TOTAL_CPU_F][TOTAL_BAUD_RATE] =
{
	// Speed Mode: NORMAL_SPEED
	{
		// CPU Frequency: F_CPU_4MHz
		{
			103, // Baud Rate: 2400
			51,  // Baud Rate: 4800 
			25,  // Baud Rate: 9600
			16,	 // Baud Rate: 14400
			12,	 // Baud Rate: 19200
			8	 // Baud Rate: 28800
		},
		// CPU Frequency: F_CPU_8MHz
		{
			207, // Baud Rate: 2400
			103, // Baud Rate: 4800
			51,  // Baud Rate: 9600
			34,  // Baud Rate: 14400
			25,  // Baud Rate: 19200
			16	 // Baud Rate: 28800
		},
		// CPU Frequency: F_CPU_16MHz
		{
			416, // Baud Rate: 2400
			207, // Baud Rate: 4800
			103, // Baud Rate: 9600
			68,  // Baud Rate: 14400
			51,  // Baud Rate: 19200
			34	 // Baud Rate: 28800
		}

	},
	// Speed Mode: DOUBLE_SPEED
	{
		// CPU Frequency: F_CPU_4MHz
		{
			207, // Baud Rate: 2400
			103, // Baud Rate: 4800
			51,  // Baud Rate: 9600
			34,  // Baud Rate: 14400
			25,  // Baud Rate: 19200
			16	 // Baud Rate: 28800
		},
		// CPU Frequency: F_CPU_8MHz
		{
			416, // Baud Rate: 2400
			207, // Baud Rate: 4800
			103, // Baud Rate: 9600
			68,  // Baud Rate: 14400
			51,  // Baud Rate: 19200
			34	 // Baud Rate: 28800
		},
		// CPU Frequency: F_CPU_16MHz
		{
			832, // Baud Rate: 2400
			416, // Baud Rate: 4800
			207, // Baud Rate: 9600
			138, // Baud Rate: 14400
			103, // Baud Rate: 19200
			68	 // Baud Rate: 28800
		}
	}
};


/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                       UART Registers BitMap                                  */
/*                                                                              */
/*------------------------------------------------------------------------------*/
enum {
    UCSRA_MPCM = 0, // Multi-processor Communication Mode
    UCSRA_U2X, // Double the USART Transmission Speed
    UCSRA_PE, // Parity Error
    UCSRA_DOR, // Data OverRun
    UCSRA_FE, // Frame Error
    UCSRA_UDRE, // USART Data Register Empty
    UCSRA_TXC, // USART Transmit Complete
    UCSRA_RXC, // USART Receive Complete
};

enum {
    UCSRB_TXB8 = 0, // Transmit Data Bit 8
    UCSRB_RXB8, // Receive Data Bit 8
    UCSRB_UCSZ2, // Character Size
    UCSRB_TXEN, // Transmitter Enable
    UCSRB_RXEN, // Receiver Enable
    UCSRB_UDRIE, // USART Data Register Empty Interrupt Enable
    UCSRB_TXCIE, // TX Complete Interrupt Enable
    UCSRB_RXCIE, // RX Complete Interrupt Enable
};

enum {
    UCSRC_UCPOL = 0, // Clock Polarity
    UCSRC_UCSZ0, // Character Size
    UCSRC_UCSZ1, // Character Size
    UCSRC_USBS, // Stop Bit Select
    UCSRC_UPM0, // Parity Mode
    UCSRC_UPM1, // Parity Mode
    UCSRC_UMSEL, // USART Mode Select
    UCSRC_URSEL, // Register Select
};


#endif // UART_PRIVATE_H