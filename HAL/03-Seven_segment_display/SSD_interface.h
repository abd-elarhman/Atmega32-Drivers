/**
 * @file SSD_interface.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  this file contains the interface of the Seven Segment Display
 *        - the polarity of the SSD (Cathode or Anode)
 *        - the connection of the SSD (Normal or BCD) , BCD (Binary Coded Decimal Converter) is used to display the numbers from 0 to 9
 *        - the display of the SSD
 *        - the display of the SSD with a dot
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H


/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  TYPEDEFS                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/

typedef enum {
    SSD_POLARITY_CATHOD,
    SSD_POLARITY_ANODE
} SSD_POLARITY_t;

typedef enum {
    SSD_CONNECTION_NORMAL,
    SSD_CONNECTION_BCD
} SSD_CONNECTION_t;


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PUPLIC Functions                               */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Display a character on a Seven Segment Display (SSD).
 *
 * This function displays a character on a specified SSD based on its ID.
 * The character can be a number (0-9), a letter (A-G or a-g), or if (greater than 15) it will display zero.
 * The function takes into account the connection type (normal or BCD) and the polarity (cathode or anode) of the SSD.
 *
 * @param copy_u8_SSD_ID The ID of the SSD to display the character on.
 * @param copy_u8Num_char The character to be displayed on the SSD.
 */
void SSD_void_display(const u8 copy_u8_SSD_ID, const u8 copy_u8Num_char);

/**
 * @brief Display a dot on a Seven Segment Display (SSD).
 *
 * This function displays a dot on a specified SSD based on its ID.
 * The function takes into account the polarity (cathode or anode) of the SSD.
 *
 * @param copy_u8_SSD_ID The ID of the SSD to display the dot on.
 */
void SSD_void_displayDot(const u8 copy_u8_SSD_ID);

#endif /* SSD_INTERFACE_H */