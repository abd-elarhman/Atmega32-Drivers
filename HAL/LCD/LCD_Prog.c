/**
 * @file LCD_Prog.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com)
 * @brief  This file contains the implementation of the LCD driver functions.
 *         The LCD driver is responsible for interfacing with the LCD hardware.
 *  	   The driver is responsible for initializing the LCD, writing data to the LCD, and setting the cursor position.
 *   	   The driver also provides the ability to write strings, numbers, and characters to the LCD.
 *    	   The driver also provides the ability to create custom characters and set the options of the LCD.
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
#include "Std_Lib.h"
#include "Utils_BitMath.h"

/*
* Include MCAL layer files
*/
//#include "MCU_config.h"
#include "DIO_Interface.h"

/*
* Include own files
*/
#include "LCD_interface.h"
#include "LCD_lcfg.h"
#include "LCD_private.h"


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
static void LCD_EN_Pulse(u8 copy_u8_LCD_ID)
{
	Dio_WritePin(LCD_arrOfLCD[copy_u8_LCD_ID].LCD_EN_Pin, DIO_VOLT_HIGH); /**< Set EN pin to high voltage */
	_delay_ms(1); /**< Delay for 1 millisecond */
	Dio_WritePin(LCD_arrOfLCD[copy_u8_LCD_ID].LCD_EN_Pin, DIO_VOLT_LOW); /**< Set EN pin to low voltage */
	_delay_ms(1); /**< Delay for 1 millisecond */
}

/**
 * @brief Writes a command to the LCD module.
 *
 * This function writes command to the LCD based on the specified LCD ID and command value.
 * It supports both 8-bit and 4-bit modes of operation.
 *
 * @param copy_u8_LCD_ID The ID of the LCD module.
 * @param cmd The command to be written.
 */
static void LCD_WriteCMD(u8 copy_u8_LCD_ID, u8 cmd)
{
	u8 i;
	Dio_WritePin(LCD_arrOfLCD[copy_u8_LCD_ID].LCD_RS_Pin, DIO_VOLT_LOW); /**< Set RS pin to low voltage */
	if (LCD_arrOfLCD[copy_u8_LCD_ID].LCD_Mode == LCD_8BIT_MODE)
	{
		for (i = 0; i < 8; i++)
		{
			Dio_WritePin(LCD_arrOfLCD[copy_u8_LCD_ID].LCD_pins[i], get_bit(cmd, (i))); /**< Write each bit of cmd to the corresponding LCD pin */
		}
		LCD_EN_Pulse(copy_u8_LCD_ID); /**< Generate enable pulse */
	}
	else if (LCD_arrOfLCD[copy_u8_LCD_ID].LCD_Mode == LCD_4BIT_MODE)
	{
		for (i = 0; i < 4; i++)
		{
			Dio_WritePin(LCD_arrOfLCD[copy_u8_LCD_ID].LCD_pins[i], get_bit(cmd, (i + 4))); /**< Write the upper 4 bits of cmd to the corresponding LCD pin */
		}
		LCD_EN_Pulse(copy_u8_LCD_ID); /**< Generate enable pulse */
		for (i = 0; i < 4; i++)
		{
			Dio_WritePin(LCD_arrOfLCD[copy_u8_LCD_ID].LCD_pins[i], get_bit(cmd, (i))); /**< Write the lower 4 bits of cmd to the corresponding LCD pin */
		}
		LCD_EN_Pulse(copy_u8_LCD_ID); /**< Generate enable pulse */
	}
}
/**
 * @brief Writes data to the LCD.
 * 
 * This function writes data to the LCD based on the specified LCD ID and data value.
 * It supports both 8-bit and 4-bit modes of operation.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param data The data to be written to the LCD.
 */
static void LCD_WriteData(u8 copy_u8_LCD_ID, u8 data)
{
	u8 i;
	Dio_WritePin(LCD_arrOfLCD[copy_u8_LCD_ID].LCD_RS_Pin,DIO_VOLT_HIGH); /**< Set the RS pin to high to indicate data mode */
	if (LCD_arrOfLCD[copy_u8_LCD_ID].LCD_Mode==LCD_8BIT_MODE)
	{
		for (i = 0; i < 8; i++)
		{
			Dio_WritePin(LCD_arrOfLCD[copy_u8_LCD_ID].LCD_pins[i], get_bit(data, (i))); /**< Write each bit of the data to the corresponding LCD pin */
		}
		LCD_EN_Pulse(copy_u8_LCD_ID); /**< Generate an enable pulse to latch the data */
	}
	else if (LCD_arrOfLCD[copy_u8_LCD_ID].LCD_Mode==LCD_4BIT_MODE)
	{
		for (i = 0; i < 4 ; i++)
		{
			Dio_WritePin(LCD_arrOfLCD[copy_u8_LCD_ID].LCD_pins[i], get_bit(data, (i+4))); /**< Write the upper 4 bits of the data to the corresponding LCD pins */
		}
		LCD_EN_Pulse(copy_u8_LCD_ID); /**< Generate an enable pulse to latch the upper 4 bits of the data */
		for (i = 0; i < 4; i++)
		{
			Dio_WritePin(LCD_arrOfLCD[copy_u8_LCD_ID].LCD_pins[i], get_bit(data, (i))); /**< Write the lower 4 bits of the data to the corresponding LCD pins */
		}
		LCD_EN_Pulse(copy_u8_LCD_ID); /**< Generate an enable pulse to latch the lower 4 bits of the data */
	}
}

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
void LCD_voidSetOption(u8 copy_u8_LCD_ID, LCD_Options_t Copy_Option)
{
	// Entry mode set
	if (Copy_Option>=LCD_DecrementedCursorShiftingOff && Copy_Option<=LCD_FixedCursorDisplayShiftedLeft)
	{
		LCD_WriteCMD(copy_u8_LCD_ID,LCD_EntryModeSetInstruction|Copy_Option); /**<Set the entry mode with the specified option.*/
		_delay_ms(LCD_CMD_Avg_time_ms);
	}
	// Cursor or Display shift
	else if (Copy_Option>=LCD_CursorShiftleft && Copy_Option<=LCD_EntireDisplayShiftRight)
	{
		LCD_WriteCMD(copy_u8_LCD_ID,LCD_CursorOrDisplayShiftInstruction|((Copy_Option-4)<<2)); /**<Shift the cursor or display with the specified option.*/
		_delay_ms(LCD_CMD_Avg_time_ms);
	}
	else if (Copy_Option>=LCD_BlinkOff && Copy_Option<=LCD_DisplayOn)
	{
		Copy_Option=(Copy_Option-8);
		LCD_u8displayOnOffControlBuffer[copy_u8_LCD_ID]|=LCD_DisplayOnOffControlInstruction;
		write_bit(LCD_u8displayOnOffControlBuffer[copy_u8_LCD_ID],(Copy_Option/2),(Copy_Option%2));
		LCD_WriteCMD(copy_u8_LCD_ID,LCD_u8displayOnOffControlBuffer[copy_u8_LCD_ID]); /**<Set the display on/off control with the specified option.*/
		_delay_ms(LCD_CMD_Avg_time_ms);
	}
	else if (Copy_Option==LCD_ClearDisplay)
	{
		LCD_WriteCMD(copy_u8_LCD_ID,0x01); /**<Clear the display.*/
		_delay_ms(LCD_Clear_Display_time_ms);
	}
	else if (Copy_Option==LCD_ReturnHome)
	{
		LCD_WriteCMD(copy_u8_LCD_ID,0x02); /**<Return the cursor to home position.*/
		_delay_ms(LCD_Return_Home_time_ms);
	}
	else
	{
		// Do nothing
	}
}

/**
 * @brief Shifts the cursor to the left and writes a space character to the LCD.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 */
void LCD_BackSpace(u8 copy_u8_LCD_ID)
{
	LCD_WriteCMD(copy_u8_LCD_ID,0x10); /**<Shift the cursor to the left.*/
	_delay_ms(LCD_CMD_Avg_time_ms);
	LCD_WriteData(copy_u8_LCD_ID,' '); /**<Write a space character to the LCD.*/
	_delay_ms(1);
	LCD_WriteCMD(copy_u8_LCD_ID,0x10); /**<Shift the cursor to the left because the cursor incremented after write ' ' .*/
	_delay_ms(LCD_CMD_Avg_time_ms);
}

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
void LCD_init(u8 copy_u8_LCD_ID)
{
	_delay_ms(LCD_poweron_time_ms);
	if (LCD_arrOfLCD[copy_u8_LCD_ID].LCD_Mode==LCD_4BIT_MODE)
	{	
		LCD_WriteCMD(copy_u8_LCD_ID,0x02);
		_delay_ms(LCD_CMD_Avg_time_ms);
	}
	// function set
	// 0b0 0 1 DL N F X X - DL:Data length() , N:No of lines , F:Font
	// DL=0 4-bit mode , DL=1 8-bit mode , N=0 1-line mode , N=1 2-line mode , F=0 5x7 dots , F=1 5x10 dots
	u8 local_u8functionSet =LCD_FunctionSetInstruction| LCD_arrOfLCD[copy_u8_LCD_ID].LCD_Mode | LCD_arrOfLCD[copy_u8_LCD_ID].LCD_LINE | LCD_arrOfLCD[copy_u8_LCD_ID].LCD_DOTS;
	LCD_WriteCMD(copy_u8_LCD_ID,local_u8functionSet); /**<Set the function set with the specified options.*/
	_delay_ms(LCD_CMD_Avg_time_ms);

	// display off control
	// 0b0 0 0 0 1 D C B - D:Display , C:Cursor , B:Blink
	// D=0 display off , D=1 display on , C=0 cursor off , C=1 cursor on , B=0 blink off , B=1 blink on
	LCD_u8displayOnOffControlBuffer[copy_u8_LCD_ID]=LCD_DisplayOnOffControlInstruction|LCD_u8displayOnOffControlBuffer[copy_u8_LCD_ID]|0b00001100;
	LCD_WriteCMD(copy_u8_LCD_ID,LCD_u8displayOnOffControlBuffer[copy_u8_LCD_ID]); /**<Set the display on/off control with the specified options.*/
	_delay_ms(LCD_CMD_Avg_time_ms);

	// clear display
	// 0 0 0 0 0 0 0 1
	LCD_WriteCMD(copy_u8_LCD_ID,0b00000001); /**<Clear the display.*/
	_delay_ms(LCD_Clear_Display_time_ms);

	// entry mode set
	// 0 0 0 0 0 0 0 1
	// 0b0 0 0 0 0 0 0 0 1 - I/D=1 , S=0
	// I/D=1 increment , I/D=0 decrement , S=1 display shift , S=0 cursor move 
	u8 local_u8EntryModeSet = LCD_EntryModeSetInstruction | LCD_IncrementedCursorShiftingOff;
	LCD_WriteCMD(copy_u8_LCD_ID,local_u8EntryModeSet); /**<Set the entry mode with the specified options.*/
	_delay_ms(LCD_CMD_Avg_time_ms);
}

/**
 * @brief Write a character to the LCD.
 * 
 * This function writes a character to the LCD display.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param ch The character to write.
 */
void LCD_WriteCh(u8 copy_u8_LCD_ID,u8 ch)
{
	LCD_WriteData(copy_u8_LCD_ID,ch); /**<Write data to the LCD.*/
	_delay_ms(1); /**<Delay for 1 millisecond.*/
}

/**
 * @brief Write a string to the LCD.
 * 
 * This function writes a string to the LCD display.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param str The string to write.
 */
void LCD_WriteStr(u8 copy_u8_LCD_ID, u8 str[])
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteCh(copy_u8_LCD_ID,str[i]); /**<Write a character to the LCD.*/
	}
}


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
void LCD_WriteNum(u8 copy_u8_LCD_ID, s64 num)
{
	u8 str[50]={0};
	u8 temp,Sign_Flag=0;
	u16 i,len;
	if (num==0)
	{
		LCD_WriteCh(copy_u8_LCD_ID,'0') ;
		return;
	}
	else
	{
		if(num<0)
		{
			Sign_Flag=1;
			num=num*(-1);
			//LCD_WriteCh('-');
		}
		for(i=0; num>0 ;i++)
		{
			str[i]=('0'+(num%10));
			num=num/10;
		}
		if(Sign_Flag==1)
		{
			str[i]='-';
			i++;
		}
		str[i]='\0';
		len=i;
		/*Swap*/
		/*
		Str_ReverseWithLen(str,len);
		LCD_WriteStr(copy_u8_LCD_ID,str);*/
		for (u8 j=i; j>0 ; j--)
		{
			LCD_WriteCh(copy_u8_LCD_ID,str[j-1]);
		}
		
	}
}

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
void LCD_WriteBin(u8 copy_u8_LCD_ID, u8 num)
{
	u8 Local_bitValue,i;
	for ( i =8; i>0 ; i--)
	{
		Local_bitValue=((num>>(i-1)) & 0x01)+'0';
		LCD_WriteCh(copy_u8_LCD_ID,Local_bitValue);
	}
}


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
void LCD_WriteBinNoLeftZeros(u8 copy_u8_LCD_ID, u8 num)
{
	u8 Local_bitValue,i,flag=0;
	for ( i =8; i>0 ; i--)
	{
		Local_bitValue=((num>>(i-1)) & 0x01)+'0';
		if (Local_bitValue=='1')
		{
			flag=1;
		}
		if (flag==1)
		{
			LCD_WriteCh(copy_u8_LCD_ID,Local_bitValue);	
		}
	}
}

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
void LCD_WriteHex(u8 copy_u8_LCD_ID, u8 num)
{
	LCD_WriteStr(copy_u8_LCD_ID,(u8*)"0X"); /**< Write the string "0X" to the LCD display. */

	if ((num>>4)<=9)
	{
		LCD_WriteCh(copy_u8_LCD_ID,(num>>4)+'0'); /**< Write the upper nibble of the number to the LCD display as a character. */
	}
	else if ((num>>4)>9)
	{
		LCD_WriteCh(copy_u8_LCD_ID,(num>>4)-10+'A'); /**< Write the upper nibble of the number to the LCD display as a hexadecimal character (A-F). */
	}

	if ((num & 0x0F)<=9)
	{
		LCD_WriteCh(copy_u8_LCD_ID,(num & 0x0F)+'0'); /**< Write the lower nibble of the number to the LCD display as a character. */
	}
	else if ((num & 0x0F)>9)
	{
		LCD_WriteCh(copy_u8_LCD_ID,(num & 0x0F)-10+'A'); /**< Write the lower nibble of the number to the LCD display as a hexadecimal character (A-F). */
	}
}

/**
 * @brief Sets the cursor position on the LCD.
 * 
 * This function sets the cursor position on the LCD based on the specified LCD ID, line, and cell.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param line The line number to set the cursor to.
 * @param cell The cell number to set the cursor to.
 */
void LCD_SetCursor(u8 copy_u8_LCD_ID,u8 line,u8 cell)
{
	/*
		Set DDRAM Address:0 0     1 AC6 AC5 AC4 AC3 AC2 AC1 AC0
	*/
	switch (line)
	{
		case 1    :
				  LCD_WriteCMD(copy_u8_LCD_ID,LCD_DDRAM_Address+LCD_DDRAM_Address_1ndLine+(cell-1)); /**< Set the cursor position to the specified line and cell on the LCD. */
				  _delay_ms(1); 
		break;
		
		case 2    :
				  LCD_WriteCMD(copy_u8_LCD_ID,LCD_DDRAM_Address+LCD_DDRAM_Address_2ndLine+(cell-1)); /**< Set the cursor position to the specified line and cell on the LCD. */
				  _delay_ms(1); 
		break;

		case 3    :
				  LCD_WriteCMD(copy_u8_LCD_ID,LCD_DDRAM_Address+LCD_DDRAM_Address_3rdLine+(cell-1)); /**< Set the cursor position to the specified line and cell on the LCD. */
				  _delay_ms(1); 
		break;

		case 4    :
				  LCD_WriteCMD(copy_u8_LCD_ID,LCD_DDRAM_Address+LCD_DDRAM_Address_4thLine+(cell-1)); /**< Set the cursor position to the specified line and cell on the LCD. */
				  _delay_ms(1); 
		break;
		default   :
				  /*	*/
		break;

	}
}

/**
 * @brief Creates a custom character on the LCD.
 * 
 * This function creates a custom character on the LCD based on the specified LCD ID, pattern, and location.
 * 
 * @param copy_u8_LCD_ID The ID of the LCD.
 * @param Pattern The pattern of the custom character to create.
 * @param Location The location of the custom character to create.
 */
void Create_Character(u8 copy_u8_LCD_ID,u8 Pattern[],u8 Location)
{

	u8 iLoop=0;

	LCD_WriteCMD(copy_u8_LCD_ID,LCD_CGRAM_Address+(Location*8)); //Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_WriteData(copy_u8_LCD_ID,Pattern[iLoop]); //Pass the bytes of pattern on LCD
	LCD_WriteCMD(copy_u8_LCD_ID,LCD_DDRAM_Address+LCD_DDRAM_Address_1ndLine+0); //Send the Address of DDRAM

}
