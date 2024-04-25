#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_


typedef struct {
	DIO_PIN_t kEYPAD_rows[ROWS];
	DIO_PIN_t kEYPAD_cols[COLS];
}keypad_pinMap_t;

extern const u8 keypad_charArray[ROWS][COLS];
extern const keypad_pinMap_t keypad_pinMap;



#endif /* KEYPAD_PRIVATE_H_ */