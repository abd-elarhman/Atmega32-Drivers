

#include "Std_Types.h"

#include "DIO_Interface.h"

#include "Keypad_Lcfg.h"
#include "Keypad_private.h"


const u8 keypad_charArray[ROWS][COLS]={ { '7'  , '8' , '9'  , '\0' },
										{ '4'  , '5' , '6'  , '\0' },
										{ '1'  , '2' , '3'  , '\0' },
										{ '\0' , '0' , '\0' , '\0' }
									  };



const keypad_pinMap_t keypad_pinMap={
	.kEYPAD_rows={PD0,PD1,PD2,PD3},
	.kEYPAD_cols={PD4,PD5,PD6,PD7}
};