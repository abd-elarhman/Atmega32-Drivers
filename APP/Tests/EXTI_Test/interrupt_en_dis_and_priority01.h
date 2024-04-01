/*01*/
{
	

#ifndef INTERRUPT_EN_DIS_AND_PRIORITY01_H_
#define INTERRUPT_EN_DIS_AND_PRIORITY01_H_


/*** LIB ***/
#include "Std_Types.h"
#include "Utils_BitMath.h"

/*** Include MCAL layer files ***/
#include "DIO_Interface.h" //MCAL
#include "ADC_Interface.h"
#include "EXTI_Interface.h"

/*** Include HAL layer files ***/
#include "MOTOR_Interface.h" //[1] struct type [2] extern [3] prototype
#include "LCD_Interface.h"
#include "LM35_Interface.h"

/*** configurations ***/
#define F_CPU 8000000
#include <util/delay.h>
/**********************/

typedef enum {
	m1,
	m2
}motor_num_t;



void EXTI_INT0_ISR (void)
{
	_delay_ms(500);
	Dio_TogglePin(PC5);	
}
void EXTI_INT1_ISR (void)
{
	_delay_ms(500);
	Dio_TogglePin(PC6);
}
void EXTI_INT2_ISR (void)
{
	_delay_ms(500);
	Dio_TogglePin(PC7);
}

int main(void)
{
	/* Replace with your application code */
	Dio_Init();
	LCD_init();
	ADC_Init();
	u8 x=0;
	/* [1] set trigger */
	EXTI_SetTrigger(EXTI_INT0,FALLING_EDGE);
	EXTI_SetTrigger(EXTI_INT1,FALLING_EDGE);
	
	/* ensure that you disable INT2 before select trigger*/
	EXTI_Disable(EXTI_INT2);
	EXTI_SetTrigger(EXTI_INT2,FALLING_EDGE);
	
	/* [2] set CallBack Functions */
	EXTI_SetCallBack(EXTI_INT0,EXTI_INT0_ISR);
	EXTI_SetCallBack(EXTI_INT1,EXTI_INT1_ISR);
	EXTI_SetCallBack(EXTI_INT2,EXTI_INT2_ISR);
	
	SREG_I_bit_Enable_Disable(DISABLE);
	
	/* [3] EN all EXTI interrupts */
	/*EXTI_Enable(EXTI_INT0);
	EXTI_Enable(EXTI_INT1);
	EXTI_Enable(EXTI_INT2);*/
	
	u8 status=0;
	while (1)
	{
		LCD_SetCursor(0,0);
		LCD_WriteStr((u8*)"Super_Loop");
		LCD_SetCursor(1,0);
		LCd_WriteNum(x++);
		_delay_ms(250);
		if (x==10)
		{
			x=0;
		}
		if (Dio_ReadPin(PC0)==LOW)
		{
			status=!status;
			
			if (status==0)
			{
				EXTI_Disable(EXTI_INT0);
				EXTI_Disable(EXTI_INT1);
				EXTI_Disable(EXTI_INT2);
				SREG_I_bit_Enable_Disable(DISABLE);
				
			}
			else if (status==1)
			{
				SREG_I_bit_Enable_Disable(DISABLE);
				EXTI_Enable(EXTI_INT0);
				EXTI_Enable(EXTI_INT1);
				EXTI_Enable(EXTI_INT2);
				SREG_I_bit_Enable_Disable(ENABLE);
			}
			while(Dio_ReadPin(PC0)==LOW);
		}
	}//while(1)
	
}//main



#endif /* INTERRUPT_EN_DIS_AND_PRIORITY01_H_ */
}

/*02*/
{
/*** LIB ***/
#include "Std_Types.h"
#include "Utils_BitMath.h"

/*** Include MCAL layer files ***/
#include "DIO_Interface.h" //MCAL
#include "ADC_Interface.h"
#include "EXTI_Interface.h"

/*** Include HAL layer files ***/
#include "MOTOR_Interface.h" //[1] struct type [2] extern [3] prototype
#include "LCD_Interface.h"
#include "LM35_Interface.h"

/*** configurations ***/
#define F_CPU 8000000
#include <util/delay.h>
/**********************/

typedef enum {
	m1,
	m2
}motor_num_t;



void EXTI_INT0_ISR (void)
{
	_delay_ms(500);
	Dio_TogglePin(PC5);	
}
void EXTI_INT1_ISR (void)
{
	_delay_ms(500);
	Dio_TogglePin(PC6);
}
void EXTI_INT2_ISR (void)
{
	_delay_ms(500);
	Dio_TogglePin(PC7);
}

int main(void)
{
	/* Replace with your application code */
	Dio_Init();
	LCD_init();
	ADC_Init();
	u8 x=0;
	/* [1] set trigger */
	EXTI_SetTrigger(EXTI_INT0,FALLING_EDGE);
	EXTI_SetTrigger(EXTI_INT1,FALLING_EDGE);
	
	/* ensure that you disable INT2 before select trigger*/
	EXTI_Disable(EXTI_INT2);
	EXTI_SetTrigger(EXTI_INT2,FALLING_EDGE);
	
	/* [2] set CallBack Functions */ // must before enable
	EXTI_SetCallBack(EXTI_INT0,EXTI_INT0_ISR);
	EXTI_SetCallBack(EXTI_INT1,EXTI_INT1_ISR);
	EXTI_SetCallBack(EXTI_INT2,EXTI_INT2_ISR);
	
	SREG_I_bit_Enable_Disable(DISABLE);
	
	/* [3] EN all EXTI interrupts */
	/*EXTI_Enable(EXTI_INT0);
	EXTI_Enable(EXTI_INT1);
	EXTI_Enable(EXTI_INT2);*/
	
	
	u8 status=0;
	while (1)
	{
		LCD_SetCursor(0,0);
		LCD_WriteStr((u8*)"i love Toto");
		LCD_SetCursor(1,0);
		LCd_WriteNum(x++);
		_delay_ms(250);
		if (x==10)
		{
			x=0;
		}
		if (Dio_ReadPin(PC0)==LOW)
		{
			status=!status;
			
			if (status==0)
			{
				EXTI_Disable(EXTI_INT0);
				EXTI_Disable(EXTI_INT1);
				EXTI_Disable(EXTI_INT2);
				SREG_I_bit_Enable_Disable(DISABLE);
				
			}
			else if (status==1)
			{
				//SREG_I_bit_Enable_Disable(DISABLE);
				//SREG_I_bit_Enable_Disable(ENABLE);
				EXTI_Enable(EXTI_INT0);
				EXTI_Enable(EXTI_INT1);
				EXTI_Enable(EXTI_INT2);
				
				SREG_I_bit_Enable_Disable(ENABLE);
			}
			while(Dio_ReadPin(PC0)==LOW);
		}
	}//while(1)
	
}//main*/
	
}




