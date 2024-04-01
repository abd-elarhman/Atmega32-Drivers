/**
 * @file UART_Services.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file is a header file that contains the prototypes of the UART services functions.
 *  	   The file contains the prototypes of the functions that send and receive data over UART using busy-waiting, asynchronous transmission, and periodic checking.
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_


/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                           Configuration Macros                               */
/*                                                                              */
/*------------------------------------------------------------------------------*/

/** @warning user must configure this macro depending on the terminal used
 * 
 */
#define PROTEUS_VT_STR_TERMINATOR   0x0d /**<PROTEUS_VIRTUAL_TERMINAL_STRING_TERMINATOR*/
#define NULL_STR_TERMINATOR 	    0x00 /**<NULL_TERMINATOR*/  
#define STRING_TERMINATOR           PROTEUS_VT_STR_TERMINATOR

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                         Static Global Vaiables                               */
/*                                                                              */
/*------------------------------------------------------------------------------*/
static volatile  Std_Bool_t isByteSended=STD_TRUE;
static u8  *Asynch_Send_Str;
static u8  *Asynch_receive_str;
static u8  *Asynch_Send_buffer;
static u8  *Asynch_receive_buffer;



/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  TYPEDEFS                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/
/***********ToDo*************/
/*
typedef enum{
	SEND_STATE,
	RECEIVE_STATE
}	Asynch_State_t;

typedef struct{
	u8 *Str;
	u8 i;
}	Asynch_t;

static Asynch_t Asynch;

typedef enum{
	TERMINATEING_STIRNG,
	NOT_TERMINATEING_STIRNG
}String_Terminate_t;
*/
/******************************/




/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PUPLIC Functions                               */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Send and Receive Functions          	               */
/*                             with busy waiting                                */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Sends a buffer of data over UART using busy-waiting.
 *
 * This function sends the contents of the specified buffer over UART using busy-waiting.
 * It waits until the UART is ready to transmit data and then sends each byte of the buffer sequentially. 
 * The function does not return until all bytes have been sent.
 *
 * @param buffer The buffer containing the data to be sent.
 */

void UART_SendBufferBusyWait(const u8 buffer[]);

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
void UART_SendStringBusyWait(const u8 Str[]);

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
void UART_ReceiveStringBusyWait(u8 Str[]);
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
static void UART_TxCallBackWithoutNull(void);

/**
 * @brief Sends a buffer of data over UART using asynchronous transmission.
 *
 * This function sends the contents of the specified buffer over UART using asynchronous transmission.
 * It sends each byte of the buffer sequentially.
 * The function returns immediately after the first byte is sent.
 *
 * @param buffer The buffer containing the data to be sent.
 */
void UART_SendBufferAsynch(u8 buffer[]);

/**
 * @brief This function is a callback function for UART transmission with null character.
 * 
 */
static void UART_TxCallBackWithNull(void);

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
void UART_SendStringAsynch (u8 Str[]);

/*Receive Function*/
/**
 * @brief This function is a callback function for UART reception without null character.
 * 
 */
static void UART_RxCallBackWithoutNull(void);

/**
 * @brief Receives a buffer of data over UART using asynchronous reception.
 *
 * This function receives a buffer of data over UART using asynchronous reception.
 * It receives each byte of the buffer sequentially.
 * The function returns immediately after the first byte is received.
 *
 * @param buffer The buffer in which to store the received data.
 */
void UART_ReceiveInBuffer_Asynch(u8 buffer[]);

/**
 * @brief This function is a callback function for UART reception with null character.
 * 
 */
static void UART_RxCallBackWithNull(void);

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
void UART_ReceiveString_Asynch(u8 Str[]);
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
static void UART_TxPeriodicCheckCallBack(void);

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
Std_Status_t UART_SendBufferPeriodicCheck(u8 buffer[]);

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
Std_Status_t UART_SendStringPeriodicCheck(u8 Str[]);

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
void UART_SendStringCheckSumBusyWait(u8 str[]);

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
Std_Error_t UART_ReceiveStringCheckSumBusyWait(u8 str[]);



#endif /* UART_SERVICES_H_ */
