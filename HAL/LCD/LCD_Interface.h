/**
 * @file LCD_Interface.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com)
 * @brief  this file contains the interfacing information of the LCD module
 *         and the prototypes of the functions of the LCD module.
 *          - LCD_voidSetOption
 *          - LCD_init
 *          - LCD_WriteCh
 *          - LCD_WriteStr
 *          - LCD_WriteNum
 *          - LCD_WriteBin
 *          - LCD_WriteBinNoLeftZeros
 *          - LCD_WriteHex
 *          - LCD_SetCursor
 *          - Create_Character
 * @version 0.1
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  TYPEDEFS                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/

typedef enum {
    LCD_1lineMode=0b00000000, /**< enum to set the 1-line mode of the LCD. */
    LCD_2lineMode=0b00001000 /**< enum to set the 2-line mode of the LCD. */
} LCD_LINE_t;

typedef enum {
    LCD_5x7Dots=0b00000000, /**< enum to set the 5x7 dots of the LCD. */
    LCD_5x10Dots=0b00000100 /**< enum to set the 5x10 dots of the LCD. */
} LCD_DOTS_t;

typedef enum {
    LCD_4BIT_MODE=0b00000000, /**< enum to set the 4-bit mode of the LCD. */
    LCD_8BIT_MODE=0b00010000  /**< enum to set the 8-bit mode of the LCD. */
} LCD_MODE_t;

typedef enum
{
	//Entry mode set
	LCD_DecrementedCursorShiftingOff=0, /**< option to decrement the cursor of the LCD. */
	LCD_FixedCursorDisplayShiftedRight, /**< option to make the cursor fixed and the LCD display shifted to the right. */
	LCD_IncrementedCursorShiftingOff, /**< option to increment the cursor of the LCD. */
	LCD_FixedCursorDisplayShiftedLeft, /**< option to make the cursor fixed and the LCD display shifted to the left. */
	
	// Cursor or Display shift
	LCD_CursorShiftleft=4,        /**< option to shift the cursor left of the LCD. */
	LCD_CursorShiftRight ,       /**< option to shift the cursor right of the LCD. */
	LCD_EntireDisplayShiftLeft , /**< option to shift the display of the LCD to the left. */
	LCD_EntireDisplayShiftRight, /**< option to shift the display of the LCD to the right. */
       
	// Display ON/OFF control
	LCD_BlinkOff=8,    /**< option to turn off the blink of the LCD. */
	LCD_BlinkOn,    /**< option to turn on the blink of the LCD. */
	LCD_CursorOff,  /**< option to turn off the cursor of the LCD. */
	LCD_CursorOn,   /**< option to turn on the cursor of the LCD. */
	LCD_DisplayOff, /**< option to turn off the display of the LCD. */
	LCD_DisplayOn,  /**< option to turn on the display of the LCD. */
	
	// Clear Display
	LCD_ClearDisplay=20, /**< option to clear the display of the LCD. */
	
	// Return Home
	LCD_ReturnHome       /**< option to return the cursor to the home position of the LCD. */
}LCD_Options_t;

typedef enum {
    LCD_Pattern1, /**< enum to set the pattern 1 of the LCD. */
    LCD_Pattern2, /**< enum to set the pattern 2 of the LCD. */
    LCD_Pattern3, /**< enum to set the pattern 3 of the LCD. */
    LCD_Pattern4, /**< enum to set the pattern 4 of the LCD. */
    LCD_Pattern5, /**< enum to set the pattern 5 of the LCD. */
    LCD_Pattern6, /**< enum to set the pattern 6 of the LCD. */
    LCD_Pattern7, /**< enum to set the pattern 7 of the LCD. */
    LCD_Pattern8  /**< enum to set the pattern 8 of the LCD. */
} LCD_Pattern_t;


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PUPLIC Functions                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/


/**
 * @brief Sets the specified option for the LCD module.
 *
 * This function is used to set the specified option for the LCD module identified by `copy_u8_LCD_ID`.
 * The available options are defined by the `LCD_Options_t` enumeration.
 *
 * @param copy_u8_LCD_ID The ID of the LCD module to set the option for.
 * @param Copy_Option The option to set for the LCD module.
 *
 * @note This function assumes that the LCD module has been initialized and configured properly.
 *
 * @example
 * // Set the LCD_BlinkOff option for LCD module 1
 * LCD_voidSetOption(1, LCD_BlinkOff);
 */
void LCD_voidSetOption(u8 copy_u8_LCD_ID, LCD_Options_t Copy_Option);

/**
 * @brief Shifts the cursor to the left and writes a space character to the LCD.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 */
void LCD_BackSpace(u8 copy_u8_LCD_ID);

/**
 * @brief Initializes the LCD.
 * 
 * This function initializes the LCD based on the specified LCD ID.
 * LCD_Ldfg.c has an array of LCD_CONFIG_t structures that contains the configuration of each LCD.
 * lcd_init() must be called before any other LCD functions.
 * It sets the function set, display off control, clears the display, and sets the entry mode.
 * @see	LCD_lcfg.c
 * @param copy_u8_LCD_ID The ID of the LCD.
 */
void LCD_init(u8 copy_u8_LCD_ID);

/**
 * @brief Write a character to the LCD.
 * 
 * This function writes a character to the LCD display.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param ch The character to write.
 */
void LCD_WriteCh(u8 copy_u8_LCD_ID,u8 ch);
/**
 * @brief Write a string to the LCD.
 * 
 * This function writes a string to the LCD display.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param str The string to write.
 */
void LCD_WriteStr(u8 copy_u8_LCD_ID, u8 str[]);


/**
 * @brief Writes a number to the LCD.
 * 
 * This function takes an LCD ID and a number as input and writes the number to the LCD.
 * If the number is negative, it also writes a '-' sign before the number.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param num The number to be written to the LCD.
 * 
 * @example
 * LCD_WriteNum(1, 12345);
 * // Writes the number 12345 to the LCD with ID 1.
 */
void LCD_WriteNum(u8 copy_u8_LCD_ID, s64 num);

/**
 * @brief Writes a binary number to the LCD.
 * 
 * This function takes a binary number and writes it to the LCD.
 * It iterates through each bit of the number and writes the corresponding value to the LCD.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param num The binary number to be written to the LCD.
 * 
 * @example
 * // Writing the binary number 00000101 to the LCD
 * LCD_WriteBin(1, 5);
 */
void LCD_WriteBin(u8 copy_u8_LCD_ID, u8 num);


/**
 * @brief Writes a binary number to the LCD without left zeros.
 *
 * This function takes a binary number and writes it to the LCD without including any left zeros.
 * It iterates through each bit of the number and writes the corresponding value to the LCD.
 * If the number contains leading zeros, they are ignored and not written to the LCD.
 *
 * @param copy_u8_LCD_ID The ID of the LCD module to write to.
 * @param num The binary number to be written to the LCD.
 *
 * @example
 * // Writing the binary number 101 to the LCD
 * LCD_WriteBinNoLeftZeros(1, 5);
 *
 * // Writing the binary number 1101 to the LCD
 * LCD_WriteBinNoLeftZeros(2, 13);
 */
void LCD_WriteBinNoLeftZeros(u8 copy_u8_LCD_ID, u8 num);

/**
 * @brief Writes a hexadecimal number to the LCD.
 * 
 * This function takes a hexadecimal number and writes it to the LCD.
 * It writes the number in the format "0xHH" where HH is the hexadecimal number.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param num The hexadecimal number to be written to the LCD.
 * 
 * @example
 * // Writing the hexadecimal number 0x2A to the LCD
 * LCD_WriteHex(1, 0x2A);
 */
void LCD_WriteHex(u8 copy_u8_LCD_ID, u8 num);

/**
 * @brief Sets the cursor position on the LCD.
 * 
 * This function sets the cursor position on the LCD based on the specified LCD ID, line, and cell.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param line The line number to set the cursor to.
 * @param cell The cell number to set the cursor to.
 */
void LCD_SetCursor(u8 copy_u8_LCD_ID,u8 line,u8 cell);

/**
 * @brief Creates a custom character on the LCD.
 * 
 * This function creates a custom character on the LCD based on the specified LCD ID, pattern, and location.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param Pattern The pattern of the custom character to create.
 * @param Location The location of the custom character to create.
 */
void Create_Character(u8 copy_u8_LCD_ID,u8 Pattern[],u8 Location);



#endif /* LCD_INTERFACE_H_ */