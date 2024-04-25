



#include "Std_Types.h"

#include "DIO_Interface.h"

#include "Keypad_Lcfg.h"
#include "Keypad_private.h"


Std_Error_t KEYPAD_GetKey(u8 *key)
{
	Std_Error_t error=STD_NOK;
	Std_Status_t isKeyPressed=STD_FALSE;
	
	u8 rowsCounter,colsCounter;
	
	// loop to make all row pins are "high volt"
	for (rowsCounter=0; rowsCounter<ROWS ;rowsCounter++)
	{
		Dio_WritePin(keypad_pinMap.kEYPAD_rows[rowsCounter],DIO_VOLT_HIGH);
	}
	
	// loop at each row pin by make it "low volt" and check for first col pin that equals to "low volt"
	for (rowsCounter=0; rowsCounter<ROWS; rowsCounter++)
	{
		Dio_WritePin(keypad_pinMap.kEYPAD_rows[rowsCounter],DIO_VOLT_LOW); /*< change this row pin to "low volt" to check which col pin is "low volt" too */
		
		for (colsCounter=0; (colsCounter<COLS)&&(isKeyPressed==STD_FALSE) ;colsCounter++)
		{
			if (keypad_charArray[rowsCounter][colsCounter] != '\0') /*< to neglect null keys that didnt needed in your application */
			{
				if (Dio_ReadPin(keypad_pinMap.kEYPAD_cols[colsCounter])==DIO_VOLT_LOW) /*< check which col pin is "low volt" */
				{
					isKeyPressed=STD_TRUE; /*< there is key pressed so it is not needed to loop more*/
					*key=keypad_charArray[rowsCounter][colsCounter]; /*< get key */
					while(Dio_ReadPin(keypad_pinMap.kEYPAD_cols[colsCounter])==DIO_VOLT_LOW);/*< busy wait until key released */
					error=STD_OK; /*< indicate that function get key successfully */
				}
			}
		}
		Dio_WritePin(keypad_pinMap.kEYPAD_rows[rowsCounter],DIO_VOLT_HIGH); /*< switch this row pin to "high volt" again */
	}
	return error;
}