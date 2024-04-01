/**
 * @file UART_Services.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file contains the implementation of the UART services.
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
 * LIB files
 */
#include "Std_Types.h"
#include "Utils_BitMath.h"

/*
 * MCAL layer files
 */
#include "UART_Interface.h"

/*
 * the module files
 */
#include "UART_Services.h"

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Send and Receive Functions          	               */
/*                             with busy waiting                                */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/*todo:
void UART_SendStringBusyWait(const u8 Str[],String_Terminate_t Terminate)
{
	u8 i = 0;
	while(Str[i] != NULL_CHAR)
	{
		UART_SendByteBusyWait(Str[i]);
		i++;
	}
	if(Terminate == TERMINATEING_STIRNG)
	{
		UART_SendByteBusyWait(NULL_CHAR);
	}
}
*/

/**
 * @brief Sends a buffer of data over UART using busy-waiting.
 *
 * This function sends the contents of the specified buffer over UART using busy-waiting.
 * It waits until the UART is ready to transmit data and then sends each byte of the buffer sequentially. 
 * The function does not return until all bytes have been sent.
 *
 * @param buffer The buffer containing the data to be sent.
 */

void UART_SendBufferBusyWait(const u8 buffer[])
{
	u8 i = 0;
	while(buffer[i] != NULL_CHAR)
	{
		UART_SendByteBusyWait(buffer[i]);
		i++;
	}
}


/**
 * @brief sends a string over UART using busy-waiting.
 * 
 * This function sends a string over UART using busy-waiting.
 * It waits until the UART is ready to transmit data and then sends each character of the string sequentially.
 * The function does not return until the entire string has been sent.
 * The string is terminated by a NULL character.
 * 
 * @param Str The string to be sent.
 */
void UART_SendStringBusyWait(const u8 Str[])
{
	u8 i = 0;
	while(Str[i] != NULL_CHAR)
	{
		UART_SendByteBusyWait(Str[i]);
		i++;
	}
	UART_SendByteBusyWait(NULL_CHAR);
	
}

/**
 * @brief Receives a string over UART using busy-waiting.
 *
 * This function receives a string over UART using busy-waiting. 
 * It waits until a NULL character is received, indicating the end of the string.
 * The function does not return until the entire string has been received.
 * The received string is stored in the specified buffer.
 *
 * @param Str The buffer in which to store the received string.
 */
void UART_ReceiveStringBusyWait(u8 Str[]) 
{
	u8 i = 0;
	Str[i] = UART_ReceiveByteBusyWait();
	while(Str[i] != STRING_TERMINATOR)
	{
		i++;
		Str[i] = UART_ReceiveByteBusyWait();
	}
	Str[i] = NULL_CHAR;
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Send and Receive Functions          	               */
/*                                Asynchronous                                 */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*Send */


/**
 * @brief This function is a callback function for UART transmission without null character.
 * 
 */
static void UART_TxCallBackWithoutNull(void)
{
	static u8 i=1;
	if(Asynch_Send_buffer[i] != NULL_CHAR)
	{
		UART_SendByteNoBlock(Asynch_Send_buffer[i]);
		i++;
	}
	else
	{
		i=1;
		UART_TX_InterruptDisable();
	}
}

/**
 * @brief Sends a buffer of data over UART using asynchronous transmission.
 *
 * This function sends the contents of the specified buffer over UART using asynchronous transmission.
 * It sends each byte of the buffer sequentially.
 * The function returns immediately after the first byte is sent.
 *
 * @param buffer The buffer containing the data to be sent.
 */
void UART_SendBufferAsynch(u8 buffer[])
{
	Asynch_Send_buffer=buffer;
	UART_TX_SetCallBack(UART_TxCallBackWithoutNull);
	UART_TX_InterruptEnable();
	UART_SendByteNoBlock(buffer[0]);
}

/**
 * @brief This function is a callback function for UART transmission with null character.
 * 
 */
static void UART_TxCallBackWithNull(void)
{
	static u8 i=1;
	static u8 nullFlag=0;
	if(Asynch_Send_Str[i] != NULL_CHAR)
	{
		UART_SendByteNoBlock(Asynch_Send_Str[i]);
		i++;
	}
	else if ( (Asynch_Send_Str[i] == NULL_CHAR) && (1!=nullFlag) )
	{
		nullFlag=1;
		UART_SendByteNoBlock(NULL_CHAR);
	}
	if (1==nullFlag)
	{
		i=1;
		nullFlag=0;
		UART_TX_InterruptDisable();
	}
	
}

/**
 * @brief Sends a string over UART using asynchronous transmission.
 *
 * This function sends a string over UART using asynchronous transmission.
 * It sends each character of the string sequentially.
 * The function returns immediately after the first character is sent.
 * The string is terminated by a NULL character.
 *
 * @param Str The string to be sent.
 */
void UART_SendStringAsynch (u8 Str[])
{
	Asynch_Send_Str=Str;
	UART_TX_SetCallBack(UART_TxCallBackWithNull);
	UART_TX_InterruptEnable();
	UART_SendByteNoBlock(Str[0]);
}

/*Receive Function*/
/**
 * @brief This function is a callback function for UART reception without null character.
 * 
 */
static void UART_RxCallBackWithoutNull(void)
{
	static u8 i=0;
	Asynch_receive_buffer[i]=UART_ReceiveByteNoBlock();
	i++;

}

/**
 * @brief Receives a buffer of data over UART using asynchronous reception.
 *
 * This function receives a buffer of data over UART using asynchronous reception.
 * It receives each byte of the buffer sequentially.
 * The function returns immediately after the first byte is received.
 *
 * @param buffer The buffer in which to store the received data.
 */
void UART_ReceiveInBuffer_Asynch(u8 buffer[])
{
	Asynch_receive_buffer=buffer;
	UART_RX_SetCallBack(UART_RxCallBackWithoutNull);
	UART_RX_InterruptEnable();
}

/**
 * @brief This function is a callback function for UART reception with null character.
 * 
 */
static void UART_RxCallBackWithNull(void)
{
	static u8 i=0;
	if (NULL_CHAR != Asynch_receive_str[i])
	{
		Asynch_receive_str[i]=UART_ReceiveByteNoBlock();
		i++;
	}
	else
	{
		i=0;
		UART_RX_InterruptDisable();
	}
}

/**
 * @brief Receives a string over UART using asynchronous reception.
 *
 * This function receives a string over UART using asynchronous reception.
 * It receives each character of the string sequentially.
 * The function returns immediately after the first character is received.
 * The string is terminated by a NULL character.
 *
 * @param Str The buffer in which to store the received string.
 */
void UART_ReceiveString_Asynch(u8 Str[])
{
	Asynch_receive_str=Str;
	UART_RX_SetCallBack(UART_RxCallBackWithNull);
	UART_RX_InterruptEnable();
}


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Send and Receive Functions          	               */
/*                           with periodic checking                            */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief This function is a callback function for UART transmission with periodic checking.
 * 
 */
static void UART_TxPeriodicCheckCallBack(void)
{
	isByteSended=STD_TRUE;
}

/**
 * @brief Sends a buffer of data over UART using periodic checking.
 *
 * This function sends the contents of the specified buffer over UART using periodic checking.
 * It sends each byte of the buffer sequentially.
 * The function returns immediately after the first byte is sent.
 * The function checks periodically if the previous byte has been sent before sending the next byte.
 * the function returns STD_pending until all bytes are sent.
 * The function returns STD_done when all bytes are sent.
 *
 * @param buffer The buffer containing the data to be sent.
 * @return The status of the transmission.
 */
Std_Status_t UART_SendBufferPeriodicCheck(u8 buffer[])
{
	static	u8 i=0;
	Std_Status_t status=STD_PENDING;
	if (0==i)
	{
		UART_TX_SetCallBack(UART_TxPeriodicCheckCallBack);
		UART_TX_InterruptEnable();
	}
	// check if the previous byte is sended or not before sending the next byte
	if(STD_TRUE==isByteSended)
	{
		if(NULL_CHAR != buffer[i])
		{
			UART_SendByteNoBlock(buffer[i]);
			i++;
			/*
			* Resetting the isByteSended to 0 , indicates that the CPU excute this function call before the UART send the previous byte.
			* This ensures proper synchronization between the CPU and UART operations.
			*/
			isByteSended=STD_FALSE;
		}
		else
		{
			i=0;
			UART_TX_InterruptDisable();
			status=STD_DONE;
		}
	}
	return status;
}

/**
 * @brief Sends a string over UART using periodic checking.
 *
 * This function sends a string over UART using periodic checking.
 * It sends each character of the string sequentially.
 * The function returns immediately after the first character is sent.
 * The function checks periodically if the previous character has been sent before sending the next character.
 * The function returns STD_pending until the entire string is sent.
 * The function returns STD_done when the entire string is sent.
 * The string is terminated by a NULL character.
 *
 * @param Str The string to be sent.
 * @return The status of the transmission.
 */
Std_Status_t UART_SendStringPeriodicCheck(u8 Str[])
{
	static	u8 i=0;
	static  u8 nullFlag=0;
	Std_Status_t status=STD_PENDING;
	if (0==i)
	{
		UART_TX_SetCallBack(UART_TxPeriodicCheckCallBack);
		UART_TX_InterruptEnable();
	}
	// check if the previous byte is sended or not before sending the next byte
	if(STD_TRUE==isByteSended)
	{
		if(NULL_CHAR != Str[i])
		{
			UART_SendByteNoBlock(Str[i]);
			i++;
			/*
			* Resetting the isByteSended to 0 , indicates that the CPU excute this function call before the UART send the previous byte.
			* This ensures proper synchronization between the CPU and UART operations.
			*/
			isByteSended=STD_FALSE;
		}
		else if(NULL_CHAR == Str[i] && 1!=nullFlag)
		{
			nullFlag=1;
			isByteSended=STD_FALSE;
			UART_SendByteNoBlock(NULL_CHAR); /*< Send the NULL_CHAR to indicate the end of the string */
		}
		else // if(NULL_CHAR == Str[i] && 1==nullFlag) 
		{
			i=0;
			UART_TX_InterruptDisable();
			status=STD_DONE;
		}
	}
	return status;
}


/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  CheckSum                                    */   
/*                             PROTOCOL ABOVE UART                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/
/*			Frame of this checkSum protocol:
			Data_Len	+	data    +	sum
size        1Byte			1Byte       2byte( (maxCharSize=255)*(maxNumOfChar=255)=65025 )
max_value   255             255         65535
*/

/**
 * @brief Sends a string over UART using busy-waiting with a checksum.
 *
 * This function sends a string over UART using busy-waiting.
 * It calculates the checksum of the string and sends it after the string.
 * The function waits until the UART is ready to transmit data and then sends each character of the string sequentially.
 * The function does not return until the entire string has been sent.
 * The string is terminated by a NULL character.
 * The checksum is calculated as the sum of all characters in the string.
 * The checksum is sent as two bytes, with the least significant byte sent first.
 *
 * @param str The string to be sent.
 */
void UART_SendStringCheckSumBusyWait(u8 str[])
{
	u8 i=0,len=0;
	u16 sum=0;

	// Calulate length of the string & the Sum of Characters
	while(NULL_CHAR != str[len])
	{
		sum+=str[len];	
		len++;
	}
	UART_SendByteBusyWait(len);

	// send the string 
	for(i=0;i<len;i++)
	{
		UART_SendByteBusyWait(str[i]);
	}

	//send the sum
	UART_SendByteBusyWait((u8)sum);
	UART_SendByteBusyWait((u8)(sum>>8));
}

/**
 * @brief Receives a string over UART using busy-waiting with a checksum.
 *
 * This function receives a string over UART using busy-waiting.
 * It calculates the checksum of the received string and compares it to the received checksum.
 * The function waits until the UART is ready to receive data and then receives the length of the string.
 * The function then receives the string and calculates the checksum.
 * The function returns STD_OK if the checksums match, and STD_NOK if they do not.
 *
 * @param str The buffer in which to store the received string.
 * @return The status of the checksum comparison.
 */
Std_Error_t UART_ReceiveStringCheckSumBusyWait(u8 str[])
{
	u8 i=0,len=0,firstbyte=0,secondbyte=0;
	u16 receivedSum=0,calculatedSum=0;
	Std_Error_t	errorStatus=STD_NOK;

	// Receive the length of the string
	len=UART_ReceiveByteBusyWait();

	// Receive the string & calculate the sum
	for(i=0;i<len;i++)
	{
		str[i]=UART_ReceiveByteBusyWait();
		calculatedSum+=str[i];
	}

	// Receive the sum
	firstbyte=UART_ReceiveByteBusyWait();
	secondbyte=UART_ReceiveByteBusyWait();
	receivedSum=((u16)secondbyte<<8)|((u16)firstbyte); 

	if(calculatedSum==receivedSum)
	{
		errorStatus=STD_OK;
	}
	else
	{
		errorStatus=STD_NOK;
	}
	return errorStatus;
}

