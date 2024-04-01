/**
 * @file UART_Lcfg.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file contains the configurations of the UART module in the microcontroller.
 *         The user must configure the speed mode, the CPU frequency, the baud rate, the parity mode, the number of data bits, the synchronization mode, and the number of stop bits.
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef UART_LCFG_H_
#define UART_LCFG_H_


/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                   CHANGE THIS PART TO YOUR NEEDS                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/******************* UART configuration*********************************/
#define  SPEED_MODE         DOUBLE_SPEED
#define  CPU_F               _8_MHZ
#define  BUAD_RATE          BAUD_9600
#define  SYNCH_MODE         ASYNCH
#define  PARITY_MODE        ODD_PARITY
#define  N_DATA_BITS        _8_DATA_BITS
#define  N_STOP_BITS        TWO_STOP_BIT
   

#endif /* UART_LCFG_H_ */