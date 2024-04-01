/**
 * @file SSD_prog.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  this file contains the implementation of the Seven Segment Display
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  Inclusion                                   */
/*                                                                              */
/*------------------------------------------------------------------------------*/
/*
 * LIB
 */
#include "Std_Types.h"
#include "Utils_BitMath.h"

/*
 * Include MCAL layer files
 */
#include "DIO_Interface.h"

/*
 * Include own files
 */
#include "SSD_interface.h"
#include "SSD_lcfg.h"
#include "SSD_private.h"

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                            Function Definitions                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/


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
void SSD_void_display(const u8 copy_u8_SSD_ID, const u8 copy_u8Num_char)
{
    // check the connection of the SSD
    if (SSD_arrOfSSD[copy_u8_SSD_ID].connection == SSD_CONNECTION_NORMAL)
    {
        u8 i, local_copy_u8Num_char;
        // check if the number is a lowerCase letter
        if ((copy_u8Num_char >= 'a') && (copy_u8Num_char <= 'g'))
        {
            local_copy_u8Num_char = (copy_u8Num_char - 'a') + 10; /*< convert the letter to a number*/
        }
        // check if the number is an upperCase letter
        else if ((copy_u8Num_char >= 'A') && (copy_u8Num_char <= 'G'))
        {
            local_copy_u8Num_char = (copy_u8Num_char - 'A') + 10; /*< convert the letter to a number*/
        }
        // check if the number is greater than 15
        else if (copy_u8Num_char > 15)
        {
            local_copy_u8Num_char = 0; /*< if the number is greater than 15, display 0*/
        }
        // if the number is a valid number
        else
        {
            local_copy_u8Num_char = copy_u8Num_char; /*< assign the number to the local variable*/
        }
        // loop over the 7 segments of the SSD
        for (i = 0; i < 7; i++)
        {
            // check the polarity of the SSD
            if (SSD_arrOfSSD[copy_u8_SSD_ID].polarity == SSD_POLARITY_CATHOD)
            {
                // common cathode means that the segment is on when the pin is high
                // the get_bit function is used to get the value of the bit at the i-th position in the lookUpTable
                // the lookUpTable is designed to display the numbers on the cathode SSD
                Dio_WritePin(SSD_arrOfSSD[copy_u8_SSD_ID].seg[i], get_bit(SSD_u8lookUpTable[local_copy_u8Num_char], i)); /*< display the number on the SSD*/
            }
            
            // common cathode means that the segment is on when the pin is low
            // the get_bit function is used to get the value of the bit at the i-th position in the lookUpTable
            // the lookUpTable is designed to display the numbers on the cathode SSD
            // so the value of the bit is inverted to display the number on the anode SSD
            else if (SSD_arrOfSSD[copy_u8_SSD_ID].polarity == SSD_POLARITY_ANODE)
            {
                // common anode means that the segment is on when the pin is low
                Dio_WritePin(SSD_arrOfSSD[copy_u8_SSD_ID].seg[i], !get_bit(SSD_u8lookUpTable[local_copy_u8Num_char], i)); /*< display the number on the SSD*/
            }
        }
    }
    // if the connection of the SSD is BCD
    else if (SSD_arrOfSSD[copy_u8_SSD_ID].connection == SSD_CONNECTION_BCD)
    {
        u8 i, local_copy_u8Num_char;
        // check if the number is a lowerCase letter
        if ((copy_u8Num_char >= 'a') && (copy_u8Num_char <= 'g'))
        {
            local_copy_u8Num_char = (copy_u8Num_char - 'a') + 10;
        }
        // check if the number is an upperCase letter
        else if ((copy_u8Num_char >= 'A') && (copy_u8Num_char <= 'G'))
        {
            local_copy_u8Num_char = (copy_u8Num_char - 'A') + 10;
        }
        // check if the number is greater than 15
        else if (copy_u8Num_char > 15)
        {
            local_copy_u8Num_char = 0;
        }
        // if the number is a valid number
        else
        {
            local_copy_u8Num_char = copy_u8Num_char;
        }
        // loop over the 4 pins of the BCD SSD
        for (i = 0; i < 4; i++)
        {
            // check the polarity of the SSD
            if (SSD_arrOfSSD[copy_u8_SSD_ID].polarity == SSD_POLARITY_CATHOD)
            {
                Dio_WritePin(SSD_arrOfSSD[copy_u8_SSD_ID].seg[i], get_bit(local_copy_u8Num_char, i)); /*< display the number on the SSD*/
            }
            else if (SSD_arrOfSSD[copy_u8_SSD_ID].polarity == SSD_POLARITY_ANODE)
            {
                Dio_WritePin(SSD_arrOfSSD[copy_u8_SSD_ID].seg[i], !get_bit(local_copy_u8Num_char, i));
            }
        }
    }
}

/**
 * @brief Display a dot on a Seven Segment Display (SSD).
 *
 * This function displays a dot on a specified SSD based on its ID.
 * The function takes into account the polarity (cathode or anode) of the SSD.
 *
 * @param copy_u8_SSD_ID The ID of the SSD to display the dot on.
 */
void SSD_void_displayDot(const u8 copy_u8_SSD_ID)
{
    if (SSD_arrOfSSD[copy_u8_SSD_ID].polarity==SSD_POLARITY_CATHOD)
    {
        Dio_WritePin(SSD_arrOfSSD[copy_u8_SSD_ID].DOT, DIO_VOLT_HIGH);
    }
    else if (SSD_arrOfSSD[copy_u8_SSD_ID].polarity==SSD_POLARITY_ANODE)
    {
        Dio_WritePin(SSD_arrOfSSD[copy_u8_SSD_ID].DOT, DIO_VOLT_LOW);
    }
}