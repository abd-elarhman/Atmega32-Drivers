/**
 * @file SSD_private.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  this file contains the private data and functions of the Seven Segment Display
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SSD_PRIVATE_H
#define SSD_PRIVATE_H

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*              DO NOT CHANGE ANYTHING BELOW THIS COMMENT                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  TYPEDEFS                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/
typedef struct {
    SSD_POLARITY_t    polarity;
    SSD_CONNECTION_t  connection;
    DIO_PIN_t         seg[7];
    DIO_PIN_t         DOT;
}SSD_CONFIG_t;

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                          Static Private Vaiables                             */
/*                                                                              */
/*------------------------------------------------------------------------------*/
extern const SSD_CONFIG_t  SSD_arrOfSSD[copy_SSD_Quantity];

                                     // 0     1     2     3     4     5     6     7     8     9     A     b     C     d     E     F
static const u8 SSD_u8lookUpTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
                                    


#endif /* SSD_PRIVATE_H */

