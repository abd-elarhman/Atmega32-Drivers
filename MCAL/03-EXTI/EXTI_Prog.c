/**
 * @file EXTI_Prog.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file contains the implementation of the functions of EXTI module in the microcontroller.
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Std_Types.h"
#include "Utils_BitMath.h"
#include "MemMap.h"
#include "Utils_interrupt.h"


#include "EXTI_Interface.h"
#include "EXTI_private.h"

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PUPLIC Functions                               */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Sets the trigger edge for the specified EXTI interrupt.
 *
 * This function sets the trigger edge for the specified EXTI interrupt.
 *
 * @param EXTI_INT The EXTI interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * @param Trigger_Edge The trigger edge to be set (LOW_LEVEL, ANY_LOGICAL_CHANGE, FALLING_EDGE, or RISING_EDGE).
 */
void EXTI_SetTrigger(EXTI_Source_t EXTI_INT, EXTI_Trigger_Edge_t Trigger_Edge)
{
	switch (EXTI_INT)
	{
		case EXTI_INT0:
			switch (Trigger_Edge)
			{
				case LOW_LEVEL:
					clear_bit(MCUCR, MCUCR_ISC00);
					clear_bit(MCUCR, MCUCR_ISC01);
					break;
				case ANY_LOGICAL_CHANGE:
					set_bit(MCUCR, MCUCR_ISC00);
					clear_bit(MCUCR, MCUCR_ISC01);
					break;
				case FALLING_EDGE:
					clear_bit(MCUCR, MCUCR_ISC00);
					set_bit(MCUCR, MCUCR_ISC01);
					break;
				case RISING_EDGE:
					set_bit(MCUCR, MCUCR_ISC00);
					set_bit(MCUCR, MCUCR_ISC01);
					break;
			}
			break;

		case EXTI_INT1:
			switch (Trigger_Edge)
			{
				case LOW_LEVEL:
					clear_bit(MCUCR, MCUCR_ISC10);
					clear_bit(MCUCR, MCUCR_ISC11);
					break;
				case ANY_LOGICAL_CHANGE:
					set_bit(MCUCR, MCUCR_ISC10);
					clear_bit(MCUCR, MCUCR_ISC11);
					break;
				case FALLING_EDGE:
					clear_bit(MCUCR, MCUCR_ISC10);
					set_bit(MCUCR, MCUCR_ISC11);
					break;
				case RISING_EDGE:
					set_bit(MCUCR, MCUCR_ISC10);
					set_bit(MCUCR, MCUCR_ISC11);
					break;
			}
			break;

		case EXTI_INT2:
			switch (Trigger_Edge)
			{
				case FALLING_EDGE:
					clear_bit(MCUCSR, MCUCSR_ISC2);
					break;
				case RISING_EDGE:
					set_bit(MCUCSR, MCUCSR_ISC2);
					break;
			}
			break;
	}
}

/**
 * @brief Clears the flag of the specified EXTI interrupt.
 *
 * This function clears the flag of the specified EXTI interrupt.
 *
 * @param EXTI_INT The EXTI interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 */
void EXTI_ClearFlag(EXTI_Source_t EXTI_INT)
{
	switch (EXTI_INT)
	{
		case   EXTI_INT0 :
		set_bit(GIFR,GIFR_INTF0);
		break;
		
		case   EXTI_INT1 :
		set_bit(GIFR,GIFR_INTF1);
		break;
		
		case   EXTI_INT2 :
		set_bit(GIFR,GIFR_INTF2);
		break;
	}
}


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Interrupt Functions                                 */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Enables the specified EXTI interrupt.
 *
 * This function enables the specified EXTI interrupt.
 *
 * @param EXTI_INT The EXTI interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 */
void EXTI_EnableInterrupt(EXTI_Source_t EXTI_INT)
{
	switch (EXTI_INT)
	{
		case EXTI_INT0:
		set_bit(GICR, GICR_INT0);
		break;

		case EXTI_INT1:
		set_bit(GICR, GICR_INT1);
		break;

		case EXTI_INT2:
		set_bit(GICR, GICR_INT2);
		break;
	}
}

/**
 * @brief Disables the specified EXTI interrupt.
 *
 * This function disables the specified EXTI interrupt.
 *
 * @param EXTI_INT The EXTI interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 */
void EXTI_DisableInterrupt(EXTI_Source_t EXTI_INT)
{
	switch (EXTI_INT)
	{
		case   EXTI_INT0 :
		clear_bit(GICR,GICR_INT0);
		break;
		
		case   EXTI_INT1 :
		clear_bit(GICR,GICR_INT1);
		break;
		
		case   EXTI_INT2 :
		clear_bit(GICR,GICR_INT2);
		break;
	}
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Call Back Functions                                 */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/**
 * @brief Sets the call back function for the specified EXTI interrupt.
 *
 * This function sets the call back function for the specified EXTI interrupt.
 *
 * @param EXTI_INT The EXTI interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * @param LocalPtr The pointer to the call back function.
 */
void EXTI_SetCallBack(EXTI_Source_t EXTI_INT, void(*LocalPtr)(void) )
{
	switch (EXTI_INT)
	{
		case   EXTI_INT0 :
		pfCallBackInt0=LocalPtr;
		break;

		case   EXTI_INT1 :
		pfCallBackInt1=LocalPtr;
		break;

		case   EXTI_INT2 :
		pfCallBackInt2=LocalPtr;
		break;
	}
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Interrupt Service Routines                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
ISR(INT0_VECT)
{
	if (pfCallBackInt0!=NULL_PTR)
	{
		pfCallBackInt0();
	}
}
ISR(INT1_VECT)
{
	if (pfCallBackInt1!=NULL_PTR)
	{
		pfCallBackInt1();
	}
}
ISR(INT2_VECT)
{
	if (pfCallBackInt2!=NULL_PTR)
	{
		pfCallBackInt2();
	}
}
