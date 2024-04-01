/**
 * @file UART_Stack.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This is a stack implementation using UART to send and receive data
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef UART_STACK_H_
#define UART_STACK_H_

#include "Std_Types.h"


/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                           Configuration Macros                               */
/*                                                                              */
/*------------------------------------------------------------------------------*/
#define  STACK_SIZE  10


/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  TYPEDEFS                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/
typedef enum
{
	STACK_EMPTY,
	STACK_FULL,
	DONE
}Stack_Status_Type;


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PUPLIC Functions                               */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief  This function is used to push data to the stack
 * 
 * @param data the data to be pushed to the stack
 * @return Stack_Status_Type the status of the stack after pushing the data
 * 	       - STACK_FULL if the stack is full
 */
Stack_Status_Type Push(u8 data);

/**
 * @brief  This function is used to pop data from the stack
 * 
 * @param Pdata the pointer to the data to be popped from the stack
 * @return Stack_Status_Type the status of the stack after popping the data
 * 	       - STACK_EMPTY if the stack is empty
 */
Stack_Status_Type Pop(u8 *Pdata);


#endif /* UART_STACK_H_ */