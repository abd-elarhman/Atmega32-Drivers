/**
 * @file LCD_Private.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com)
 * @brief  this file contains the private functions and the static global variables of the LCD driver.
 * @version 0.1
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*              DO NOT CHANGE ANYTHING BELOW THIS COMMENT                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  MACROS                                      */
/*                                                                              */
/*------------------------------------------------------------------------------*/
// Time Delay Constants
#define LCD_poweron_time_ms       50 /**< Macro to define the time taken to power on the LCD. */
#define LCD_Clear_Display_time_ms 2 /**< Macro to define the time taken to clear the display of the LCD. */
#define LCD_Return_Home_time_ms   2 /**< Macro to define the time taken to return the cursor to the home position of the LCD. */
#define LCD_CMD_Avg_time_ms       1 /**< Macro to define the time taken to set the entry mode of the LCD. */

// Select LCD Function
#define LCD_EntryModeSetInstruction         0b00000100 /**< the entry mode set instruction of the LCD. */
#define LCD_DisplayOnOffControlInstruction  0b00001000 /**< the display on/off control instruction of the LCD. */
#define LCD_CursorOrDisplayShiftInstruction 0b00010000 /**< the cursor or display shift instruction of the LCD. */
#define LCD_FunctionSetInstruction          0b00100000 /**< the function set instruction of the LCD. */

#define LCD_DDRAM_Address 0x80 /**< Macro to define the DDRAM address of the LCD. */
#define LCD_CGRAM_Address 0x40 /**< Macro to define the CGRAM address of the LCD. */

#define LCD_DDRAM_Address_1ndLine 0x00 /**< Macro to define the DDRAM address of the 2nd line of the LCD. */
#define LCD_DDRAM_Address_2ndLine 0x40 /**< Macro to define the DDRAM address of the 2nd line of the LCD. */
#define LCD_DDRAM_Address_3rdLine 0x14 /**< Macro to define the DDRAM address of the 3rd line of the LCD. */
#define LCD_DDRAM_Address_4thLine 0x54 /**< Macro to define the DDRAM address of the 4th line of the LCD. */

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  TYPEDEFS                                    */
/*                                                                              */
/*------------------------------------------------------------------------------*/
typedef struct 
{
    LCD_MODE_t LCD_Mode;
    LCD_LINE_t LCD_LINE;
    LCD_DOTS_t LCD_DOTS;
    u8 LCD_RS_Pin;
    u8 LCD_EN_Pin;
    u8 LCD_pins[8];
}LCD_CONFIG_t;

/*------------------------------------------------------------------------------*/
/*                                                                              */
/*                                  Static Global Varibles                      */
/*                                                                              */
/*------------------------------------------------------------------------------*/

/*
* defualt is: Display off , Cursor off , Blink off 
*/
static u8 LCD_u8displayOnOffControlBuffer[copy_LCD_Quantity] ={0}; /**< static array (Act as "R/W" REG) to set the display on/off control of the LCD. */

extern const LCD_CONFIG_t  LCD_arrOfLCD[copy_LCD_Quantity];


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              PRIVATE Functions                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Generates a pulse on the enable (EN) pin of the LCD.
 *
 * This function generates a pulse on the enable (EN) pin of the LCD to initiate data transfer or command execution.
 * It sets the EN pin to high voltage for a short duration, then sets it back to low voltage.
 *
 * @param copy_u8_LCD_ID The ID of the LCD module.
 */
static void LCD_EN_Pulse(u8 copy_u8_LCD_ID);

/**
 * @brief Writes a command to the LCD module.
 *
 * This function writes command to the LCD based on the specified LCD ID and command value.
 * It supports both 8-bit and 4-bit modes of operation.
 *
 * @param copy_u8_LCD_ID The ID of the LCD module.
 * @param cmd The command to be written.
 */
static void LCD_WriteCMD(u8 copy_u8_LCD_ID, u8 cmd);

/**
 * @brief Writes data to the LCD.
 * 
 * This function writes data to the LCD based on the specified LCD ID and data value.
 * It supports both 8-bit and 4-bit modes of operation.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param data The data to be written to the LCD.
 */
static void LCD_WriteData(u8 copy_u8_LCD_ID, u8 data);

#endif /* LCD_PRIVATE_H_ */