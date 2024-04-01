/**
 * @file Std_Lib.c
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file is a source file that contains the standard library functions
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Std_Types.h"
#include "Utils_BitMath.h"
#include "Std_Lib.h"


void Str_ReverseWithLen(u8 str[],u8 len)
{
	u8 i;
	u8 j=len-1;
	u8 temp=0;
	for ( i = 0; i < j; i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}