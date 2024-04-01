/************************************************************************/
/*                            Inclusion                                 */
/************************************************************************/
/*
* LIB
*/
#include "Std_Types.h"
#include "Utils_BitMath.h"
#include "Utils_interrupt.h"

/*
* Include MCAL layer files
*/
#include "MCU_config.h"
#include "DIO_Interface.h"
#include "UART_interface.h"
#include "EXTI_Interface.h"


/*
* Include Services layer files
*/
#include "UART_Services.h"
#include "UART_Stack.h"

/*
* Include HAL layer files
*/
#include "SSD_interface.h"
#include "LCD_Interface.h"

/* ===================================================================== */
/*                           SSD                                         */
/* ===================================================================== */
enum {
	SSD_ID_ONE,
	SSD_ID_TEN
};
void App_count0to99 (void)
{
	u8 i;
	for (i=0;i<100;i++)
	{
		SSD_void_display(SSD_ID_ONE,i%10);
		SSD_void_display(SSD_ID_TEN,i/10);
		_delay_ms(250);
	}
}
/* ===================================================================== */
/*                           LCD                                         */
/* ===================================================================== */
enum {
	LCD_ID1,
	LCD_ID2
	};




/************************************************************************/
/*                              GLOBAL                                  */
/************************************************************************/
void EXTI_callBackISR(void);
void UART_rxCallBackISR(void);
static volatile u8 EXTI_eventFlag=0,UART_isStackFull=0;

int main(void)
{
	/************************************************************************/
	/*                           Initialization                             */
	/************************************************************************/
	Dio_Init();
	UART_Init();
	LCD_init(LCD_ID1);
	LCD_init(LCD_ID2);
	
	// EXTI Configuration
	EXTI_SetTrigger(EXTI_INT0,FALLING_EDGE);
	EXTI_SetCallBack(EXTI_INT0,EXTI_callBackISR);
	Global_Interrupt_Enable__asm();
	EXTI_EnableInterrupt(EXTI_INT0);
	
	// UART Configuration
	UART_RX_SetCallBack(UART_rxCallBackISR);
	UART_RX_InterruptEnable();
	
	// application code
	LCD_SetCursor(LCD_ID2,1,1);
	LCD_WriteStr(LCD_ID2,(u8*)"Stack size is 10");
	
	UART_SendStringBusyWait((u8*)"start sending\r\n");
	
	
	u8 i=0;
	u8 popedData;
	Stack_Status_Type stackStatus;
	// Super_Loop
	while (1)
	{
	
	    if (EXTI_eventFlag==1)
	    {
		    stackStatus=Pop(&popedData);
		    if (stackStatus==STACK_EMPTY)
		    {
				LCD_SetCursor(LCD_ID2,2,1);
				LCD_WriteStr(LCD_ID2,(u8*)"stack empty");
		    }
		    else
		    {
				LCD_SetCursor(LCD_ID2,2,1);
				LCD_WriteStr(LCD_ID2,(u8*)"                  ");
				LCD_SetCursor(LCD_ID2,2,1);
				LCD_WriteCh(LCD_ID2,popedData);
		    }
		    EXTI_eventFlag=0;
	    }
		
	    if (UART_isStackFull==1)
	    {
			LCD_SetCursor(LCD_ID2,2,1);
			LCD_WriteStr(LCD_ID2,(u8*)"stack full");
			UART_SendStringBusyWait((u8*)"stack full\r\n");
		    UART_isStackFull=0;
	    }
	
		// BackGround Code
		SSD_void_display(SSD_ID_ONE,i%10);
		SSD_void_display(SSD_ID_TEN,i/10);
		i++;
		if (100==i)
		{
			i=0;
		}	
		_delay_ms(250);
		
	}//while(1) Super_Loop
}//main

void EXTI_callBackISR(void)
{
	EXTI_eventFlag=1;
}

void UART_rxCallBackISR(void)
{
	u8 data;
	
	// read uart buffer
	data=UART_ReceiveByteNoBlock();
	
	if(Push(data)==STACK_FULL)
	{
		UART_isStackFull=1;
	}

}


