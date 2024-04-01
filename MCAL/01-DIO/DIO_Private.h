/**
 * @file DIO_Private.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief   This file is a header file that contains the private definitions and functions that are used in the DIO driver
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PRIVATE Functions                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
static void Dio_SetPinDirection(const DIO_PIN_t pin,const DIO_PIN_DIRECTION_t direction);

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PRIVATE Definitions                            */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
extern const DIO_PIN_DIRECTION_t arrOfPinsStatus[DIO_TOTAL_PINS];

#endif /* DIO_PRIVATE_H_ */