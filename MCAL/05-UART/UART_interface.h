/**
 * @file UART_interface.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file contains the interfacing information of UART module in the microcontroller.
 *         The file contains the public functions and the public configurations of the UART module.
 *         The user must include this file in the application code and configure the UART module using the configurations provided.
 *         The user must call the UART_Init function before using any other function of the UART module.
 *         The user can send and receive data using the UART module using the provided functions.
 *         The user can also enable and disable the transmission and reception functionality of the UART module.
 *         The user can also enable and disable the UART module interrupts and set call back functions for the interrupts.
 *         The user can also send and receive data using the UART module with busy waiting or with periodic checking.
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*              DO NOT CHANGE ANYTHING BELOW THIS COMMENT                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/********************speed mode*************************/
#define NORMAL_SPEED      0
#define DOUBLE_SPEED      1
#define TOTAL_SPEED_MODE  2
/********************cpu freqs***************************/
#define   _4_MHZ         0
#define   _8_MHZ         1
#define  _16_MHZ         2
#define  TOTAL_CPU_F     3
/*******************baud rate *****************************/
#define  BAUD_2400       0
#define  BAUD_4800       1
#define  BAUD_9600       2
#define  BAUD_14400      3
#define  BAUD_19200      4
#define  BAUD_28800      5
#define  TOTAL_BAUD_RATE 6
/*******************parity mode*************************/
#define NO_PARITY    0
#define EVEN_PARITY  1
#define ODD_PARITY   2
/*************** number of data bits********************/
#define  _5_DATA_BITS    5
#define  _6_DATA_BITS    6
#define  _7_DATA_BITS    7
#define  _8_DATA_BITS    8
#define  _9_DATA_BITS    9

/***************      sync mode*************************/
#define  SYNCH  0
#define  ASYNCH 1
/************    number of stop bits*****************/
#define  ONE_STOP_BIT   1
#define  TWO_STOP_BIT   2


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PUPLIC Functions                               */
/*                                                                             */
/*-----------------------------------------------------------------------------*/


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
void UART_TxEnable(void);

/**
 * @brief Disables the transmission functionality of the UART module.
 *
 * This function disables the transmission functionality of the UART module.
 * After calling this function, the UART module will not be able to transmit data.
 */
void UART_TxDisable(void);

/**
 * @brief Enables the reception functionality of the UART module.
 *
 * This function enables the reception functionality of the UART module.
 * After calling this function, the UART module will be able to receive data.
 */
void UART_RxEnable(void);

/**
 * @brief Disables the reception functionality of the UART module.
 *
 * This function disables the reception functionality of the UART module.
 * After calling this function, the UART module will not be able to receive data.
 */
void UART_RxDisable(void);

/**
 * @brief Initializes the UART module.
 *
 * This function initializes the UART module with the configuration set by the user.
 * The user must call this function before using any other function of the UART module.
 */
void UART_Init(void);

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
void UART_SendByteNoBlock(const u8 data);

/**
 * @brief Receives a byte using the UART module without checking the status of the UART module.
 *
 * This function receives a byte using the UART module without checking the status of the UART module.
 * The function reads the byte from the UART data register and returns immediately.
 * The function does not wait for the UART module to receive data.
 * 
 * @return The byte received using the UART module.
 */
u8 UART_ReceiveByteNoBlock(void);

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
 * The function waits until the UART module is ready to send data.
 * The function then writes the byte to the UART data register and returns.
 * 
 * @param data The byte to be sent using the UART module.
 */
void UART_SendByteBusyWait(const u8 data);

/**
 * @brief Receives a byte using the UART module with busy waiting.
 *
 * This function receives a byte using the UART module with busy waiting.
 * The function waits until the UART module receives data.
 * The function then reads the byte from the UART data register and returns.
 * 
 * @return The byte received using the UART module.
 */
u8 UART_ReceiveByteBusyWait(void);

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
Std_Status_t UART_ReceiveBytePeriodicCheck(u8*pdata);

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Interrupt Functions                                 */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
 void UART_RX_InterruptEnable(void);
 void UART_RX_InterruptDisable(void);
 void UART_TX_InterruptEnable(void);
 void UART_TX_InterruptDisable(void);

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                         Call Back Functions                                 */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void UART_RX_SetCallBack(void (*pfCallBack)(void));
void UART_TX_SetCallBack(void (*pfCallBack)(void));
void UART_UDRE_SetCallBack(void (*pfCallBack)(void));




#endif // UART_INTERFACE_H