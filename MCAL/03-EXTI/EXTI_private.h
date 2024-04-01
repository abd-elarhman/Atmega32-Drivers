/**
 * @file EXTI_private.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file contains the private information of EXTI module in the microcontroller.
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*              DO NOT CHANGE ANYTHING BELOW THIS COMMENT                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                     Static Private Global Vaiables                           */
/*                                                                              */
/*------------------------------------------------------------------------------*/
static void(*pfCallBackInt0)(void)=NULL_PTR;
static void(*pfCallBackInt1)(void)=NULL_PTR;
static void(*pfCallBackInt2)(void)=NULL_PTR;

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  TYPEDEFS                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/
/* MCU Control Register MCUCR */
enum {
	MCUCR_ISC00=0,  // Interrupt Sense Control BIT0 FOR EXTI_INT0
	MCUCR_ISC01=1,    // Interrupt Sense Control BIT1 FOR EXTI_INT0 
	MCUCR_ISC10=2,    // Interrupt Sense Control BIT0 FOR EXTI_INT1
	MCUCR_ISC11=3	  // Interrupt Sense Control BIT1 FOR EXTI_INT1
	/* bit 4:7 dosn't for EXTI */
	};
	
/* MCU Control and Status Register  MCUCSR */
enum {
	/* bit 0:4 doesn't for EXTI */
	/* bit 5 reserved */
	MCUCSR_ISC2 =6,
	/* bit 7 doesn't for EXTI */
    };
	
/* General Interrupt Control Register GICR */
enum {
	/* bit 0,1 dosnt for EXTI */
	/* bit 2:4 reserved */
	GICR_INT2=5,
	GICR_INT0=6,
	GICR_INT1=7
    };
	
/* General Interrupt Flag Register GIFR */ 
enum {
	/* bit 0:4 reserved */
	GIFR_INTF2=5,
	GIFR_INTF0=6,
	GIFR_INTF1=7
    };



#endif /* EXTI_PRIVATE_H_ */