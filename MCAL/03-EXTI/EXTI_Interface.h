/**
 * @file EXTI_Interface.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file contains the interfacing information of EXTI module in the microcontroller.
 *  	 The file contains the public functions and the public configurations of the EXTI module.
 *  	 The user can set the trigger edge of the interrupt, enable and disable the interrupt, clear the interrupt flag and set call back functions for the interrupts.
 *  	 The user can also enable and disable the EXTI module interrupts.
 *  	 The user can also set call back functions for the interrupts.
 *  	 The user can also enable and disable the EXTI module interrupts.
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  TYPEDEFS                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/
typedef enum {
	EXTI_INT0,
	EXTI_INT1,
	EXTI_INT2
	}EXTI_Source_t;

typedef enum {
	LOW_LEVEL,          // The low level of EXTI_INT generates an interrupt request.
	ANY_LOGICAL_CHANGE, // Any logical change on EXTI_INT generates an interrupt request.
	FALLING_EDGE,       // The falling edge of EXTI_INT generates an interrupt request.
	RISING_EDGE         // The rising edge of EXTI_INT generates an interrupt request.
	}EXTI_Trigger_Edge_t;

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
void EXTI_SetTrigger(EXTI_Source_t EXTI_INT, EXTI_Trigger_Edge_t Trigger_Edge);

/**
 * @brief Clears the flag of the specified EXTI interrupt.
 *
 * This function clears the flag of the specified EXTI interrupt.
 *
 * @param EXTI_INT The EXTI interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 */
void EXTI_ClearFlag(EXTI_Source_t EXTI_INT);

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
void EXTI_EnableInterrupt(EXTI_Source_t EXTI_INT);

/**
 * @brief Disables the specified EXTI interrupt.
 *
 * This function disables the specified EXTI interrupt.
 *
 * @param EXTI_INT The EXTI interrupt source (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 */
void EXTI_DisableInterrupt(EXTI_Source_t EXTI_INT);
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
void EXTI_SetCallBack(EXTI_Source_t EXTI_INT, void(*LocalPtr)(void) );
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Interrupt Service Routines                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
ISR(INT0_VECT);

ISR(INT1_VECT);

ISR(INT2_VECT);

#endif /* EXTI_INTERFACE_H_ */