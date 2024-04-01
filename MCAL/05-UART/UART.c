/**
 * @file UART.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  UART driver implementation file 
 *  	   This file contains the implementation of the UART driver functions
 *  	   The UART driver is responsible for sending and receiving data using the UART protocol
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
 * LIB files
 */
#include "Std_Types.h"
#include "MemMap.h"
#include "Utils_interrupt.h"
#include "Utils_BitMath.h"

/*
 * the module files
 */
#include "UART_Interface.h"
#include "UART_Lcfg.h"
#include "UART_Private.h"

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         initialization Functions                            */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Enables the transmission functionality of the UART module.
 *
 * This function enables the transmission functionality of the UART module.
 * After calling this function, the UART module will be able to transmit data.
 */
void UART_TxEnable(void)
{
	set_bit(UCSRB,UCSRB_TXEN);
}

/**
 * @brief Disables the transmission functionality of the UART module.
 *
 * This function disables the transmission functionality of the UART module.
 * After calling this function, the UART module will not be able to transmit data.
 */
void UART_TxDisable(void)
{
	clear_bit(UCSRB,UCSRB_TXEN);
}

/**
 * @brief Enables the reception functionality of the UART module.
 *
 * This function enables the reception functionality of the UART module.
 * After calling this function, the UART module will be able to receive data.
 */
void UART_RxEnable(void)
{
	set_bit(UCSRB,UCSRB_RXEN);
}

/**
 * @brief Disables the reception functionality of the UART module.
 *
 * This function disables the reception functionality of the UART module.
 * After calling this function, the UART module will not be able to receive data.
 */
void UART_RxDisable(void)
{
	clear_bit(UCSRB,UCSRB_RXEN);
}

/**
 * @brief Initializes the UART module.
 *
 * This function initializes the UART module with the configurations specified in the configuration file.
 * The function sets the baud rate, data bits, stop bits, parity mode, and other configurations.
 */							
void UART_Init(void)
{
	u8  UCSRC_var=0;
	u16 UBRR_var=0; 
	
	// transmission speed
	#if (SPEED_MODE==NORMAL_SPEED)
	clear_bit(UCSRA,UCSRA_U2X);
	#elif (SPEED_MODE==DOUBLE_SPEED)
	set_bit(UCSRA,UCSRA_U2X);
	#endif

    // set URSEL to write data to UCSRC register
    set_bit(UCSRC_var,UCSRC_URSEL);
 
    //USART Mode
	#if (SYNCH_MODE==SYNCH)
	set_bit(UCSRC_var,UCSRC_UMSEL)
	#elif (SYNCH_MODE==ASYNCH)
 	clear_bit(UCSRC_var,UCSRC_UMSEL);
	#endif

	// parity mode
	#if (PARITY_MODE==NO_PARITY)
	clear_bit(UCSRC_var,UCSRC_UPM0);
	clear_bit(UCSRC_var,UCSRC_UPM1);
	#elif (PARITY_MODE==EVEN_PARITY)
	clear_bit(UCSRC_var,UCSRC_UPM0);
	set_bit(UCSRC_var,UCSRC_UPM1);
	#elif (PARITY_MODE==ODD_PARITY)
	set_bit(UCSRC_var,UCSRC_UPM0);
	set_bit(UCSRC_var,UCSRC_UPM1);
	#endif
	
	// Data bits
	#if (N_DATA_BITS==_5_DATA_BITS)
	clear_bit(UCSRC_var,UCSRC_UCSZ0);
	clear_bit(UCSRC_var,UCSRC_UCSZ1);
	clear_bit(UCSRB,UCSRB_UCSZ2);
	#elif (N_DATA_BITS==_6_DATA_BITS)
	set_bit(UCSRC_var,UCSRC_UCSZ0);
	clear_bit(UCSRC_var,UCSRC_UCSZ1);
	clear_bit(UCSRB,UCSRB_UCSZ2);
    #elif (N_DATA_BITS==_7_DATA_BITS)
    clear_bit(UCSRC_var,UCSRC_UCSZ0);
    set_bit(UCSRC_var,UCSRC_UCSZ1);
	clear_bit(UCSRB,UCSRB_UCSZ2);
	#elif (N_DATA_BITS==_8_DATA_BITS)
	set_bit(UCSRC_var,UCSRC_UCSZ0);
	set_bit(UCSRC_var,UCSRC_UCSZ1);
	clear_bit(UCSRB,UCSRB_UCSZ2);
	#elif (N_DATA_BITS==_9_DATA_BITS)
	set_bit(UCSRC_var,UCSRC_UCSZ0);
	set_bit(UCSRC_var,UCSRC_UCSZ1);
	set_bit(UCSRB,UCSRB_UCSZ2);
	#endif

	// stop bits
	#if (N_STOP_BITS==ONE_STOP_BIT)
	clear_bit(UCSRC_var,UCSRC_USBS);
	#elif (N_STOP_BITS==TWO_STOP_BIT)
	set_bit(UCSRC_var,UCSRC_USBS);
	#endif

	// write the value of UCSRC_var to UCSRC register	
	UCSRC=UCSRC_var;

	// set the value of UBRR_var to UBRRH and UBRRL registers
    UBRR_var=BaudRateArray[SPEED_MODE][CPU_F][BUAD_RATE];
	UBRRH = (u8)(UBRR_var>>8);
	UBRRL = (u8)UBRR_var;

	//enable UART  receiver.
	set_bit(UCSRB,UCSRB_RXEN);
	//enable UART  transmitter .
	set_bit(UCSRB,UCSRB_TXEN);
}


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Send and Receive Functions          	               */
/*                             with no ckecking                                */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Sends a byte using the UART module without checking the status of the UART module.
 *
 * This function sends a byte using the UART module without checking the status of the UART module.
 * The function writes the byte to the UART data register and returns immediately.
 * The function does not wait for the UART module to be ready to send data.
 * 
 * @param data The byte to be sent using the UART module.
 */
void UART_SendByteNoBlock(const u8 data)
{
	UDR = data;
}

/**
 * @brief Receives a byte using the UART module without checking the status of the UART module.
 *
 * This function receives a byte using the UART module without checking the status of the UART module.
 * The function reads the byte from the UART data register and returns immediately.
 * The function does not wait for the UART module to receive data.
 * 
 * @return The byte received using the UART module.
 */
u8 UART_ReceiveByteNoBlock(void)
{
    return UDR;
}


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Send and Receive Functions          	               */
/*                             with busy waiting                                */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Sends a byte using the UART module with busy waiting.
 *
 * This function sends a byte using the UART module with busy waiting.
 * The function waits until the UART data register is empty and ready to send a new byte.
 * The function then writes the byte to the UART data register and returns.
 * 
 * @param data The byte to be sent using the UART module.
 */
void UART_SendByteBusyWait(const u8 data)
{
	/*UDRE flag is set when the buffer is empty and ready
	for transmitting a new byte so wait until this flag is set to one 
	and it will cleared by hardware when you write new data to register.*/

	while(get_bit(UCSRA,UCSRA_UDRE)!=DATA_REG_EMPTY);  
	UDR = data;
}

/**
 * @brief Receives a byte using the UART module with busy waiting.
 *
 * This function receives a byte using the UART module with busy waiting.
 * The function waits until the UART data register is full and has a new byte to be read.
 * The function then reads the byte from the UART data register and returns.
 * 
 * @return The byte received using the UART module.
 */
u8 UART_ReceiveByteBusyWait(void)
{
	/*RXC flag is set when the UART receive data so  wait until this flag is set to one
	and it will cleared by hardware when you read the data*/
	while(get_bit(UCSRA,UCSRA_RXC)!=RX_COMPLETE);  
    return UDR;
}


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Send and Receive Functions          	               */
/*                           with periodic checking                            */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Receives a byte using the UART module with periodic checking.
 *
 * This function receives a byte using the UART module with periodic checking.
 * The function checks the UART data register periodically to see if a new byte is received.
 * The function returns the status of the operation and the received byte.
 * 
 * @param pdata A pointer to a variable to store the received byte.
 * @return The status of the operation.
 */
Std_Status_t UART_ReceiveBytePeriodicCheck(u8*pdata)
{
	Std_Status_t status=STD_PENDING;
	if(get_bit(UCSRA,UCSRA_RXC))
	{
		*pdata=UDR;
		status=STD_DONE;
	}
	else
	{	
		status=STD_PENDING;
	}
return status;
}


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Interrupt Functions                                 */
/*                                                                             */
/*-----------------------------------------------------------------------------*/


 void UART_RX_InterruptEnable(void) 
{
	set_bit(UCSRB,UCSRB_RXCIE);
}

 void UART_RX_InterruptDisable(void)
{
	clear_bit(UCSRB,UCSRB_RXCIE);
}

 void UART_TX_InterruptEnable(void)
{
	set_bit(UCSRB,UCSRB_TXCIE);
}

 void UART_TX_InterruptDisable(void)
{
	clear_bit(UCSRB,UCSRB_TXCIE);
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Call Back Functions                                 */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

void UART_RX_SetCallBack(void (*pfCallBack)(void))
{
	pfCallBackUartRXC = pfCallBack;
}

void UART_TX_SetCallBack(void (*pfCallBack)(void))
{
	pfCallBackUartTXC = pfCallBack;
}

void UART_UDRE_SetCallBack(void (*pfCallBack)(void))
{
	pfCallBackUartUDRE = pfCallBack;
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Interrupt Service Routines                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
 ISR(USART_RXC_VECT)
{
	if (pfCallBackUartRXC!=NULL_PTR)
	{
		pfCallBackUartRXC();
	}
}

 ISR(USART_TXC_VECT)
{
	if (pfCallBackUartTXC!=NULL_PTR)
	{
		pfCallBackUartTXC();
	}
}

 ISR(USART_UDRE_VECT)
{
	if (pfCallBackUartUDRE!=NULL_PTR)
	{
		pfCallBackUartUDRE();
	}
}






