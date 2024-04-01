/**
 * @file LCD_Lcfg.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com)
 * @brief  this file contains the configuration of the LCD
 *          - the mode of the LCD (8bit or 4bit)
 *          - the number of lines of the LCD (1 or 2)
 *          - the number of dots of the LCD (5x7 or 5x10)
 *          - the pins of the LCD
 *          - the RS pin of the LCD
 *          - the EN pin of the LCD    
 * @version 0.1
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
* LIB
*/
#include "Std_Types.h"

/*
* Include MCAL layer files
*/
#include "DIO_Interface.h"

/*
* Include own files
*/
#include "LCD_interface.h"
#include "LCD_lcfg.h"
#include "LCD_private.h"


/*
*  LCD_line : to set the number of lines of the LCD
*  LCD_1lineMode: for 1*80 LCD
*  LCD_2lineMode: for any lcd with more than one row
*                 EX: 2*40 LCD ,2*16  LCD , 2*8 LCD , 4*20 LCD,.. (ROW*2)*(COLx) LCD
*  - the mode of the LCD (8bit or 4bit)
*  - the number of lines of the LCD (1 or 2)
*  - the number of dots of the LCD (5x7 or 5x10)
*  - the pins of the LCD
*  - the RS pin of the LCD
*  - the EN pin of the LCD
*/
const LCD_CONFIG_t  LCD_arrOfLCD[copy_LCD_Quantity]=
{
	 {
	     .LCD_Mode=LCD_4BIT_MODE,
	     .LCD_LINE=LCD_2lineMode,
	     .LCD_DOTS=LCD_5x7Dots,
	     .LCD_RS_Pin=PB0,
	     .LCD_EN_Pin=PB1,
	     .LCD_pins={PC0,PC1,PC2,PC3}
     },
     {
	     .LCD_Mode=LCD_4BIT_MODE,
	     .LCD_LINE=LCD_2lineMode,
	     .LCD_DOTS=LCD_5x7Dots,
	     .LCD_RS_Pin=PB2,
	     .LCD_EN_Pin=PB3,
	     .LCD_pins={PC4,PC5,PC6,PC7}
     }
};
