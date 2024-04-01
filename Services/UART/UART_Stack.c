/**
 * @file UART_Stack.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This is a stack implementation using UART to send and receive data
 * @version 0.1
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "UART_Stack.h"

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                          Static Global Vaiables                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/
static u8 Stack[STACK_SIZE];
static u8 SP=0;

/**
 * @brief  This function is used to push data to the stack
 * 
 * @param data the data to be pushed to the stack
 * @return Stack_Status_Type the status of the stack after pushing the data
 * 	       - STACK_FULL if the stack is full
 */
Stack_Status_Type Push(u8 data)
{
	Stack_Status_Type Status;
	if(SP==STACK_SIZE)
	{
		Status= STACK_FULL;
	}
	else
	{
		Stack[SP]=data;
		SP++;
		Status= DONE;
	}
	return Status;
}

/**
 * @brief  This function is used to pop data from the stack
 * 
 * @param Pdata the pointer to the data to be popped from the stack
 * @return Stack_Status_Type the status of the stack after popping the data
 * 	       - STACK_EMPTY if the stack is empty
 */
Stack_Status_Type Pop(u8 *Pdata)
{
		Stack_Status_Type Status;
		if(SP==0)
		{
			Status= STACK_EMPTY;
		}
		else
		{
			SP--;
			*Pdata=Stack[SP];
			Status= DONE;
		}
		return Status;
}