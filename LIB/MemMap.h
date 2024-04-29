/**
 * @file MemMap.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file is a header file that contains the memory map of the AVR microcontroller
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MEMMAP_H_
#define MEMMAP_H_
#include "Std_Types.h"

/*=============================== Memory Map ==========================*/
#define   RAM_START    0x60
#define   RAM_END      0xFF

/* ================================ Registers ==========================*/

// General Purpose I/O Registers
/*====PORTA====*/
#define   PORTA        (*(volatile u8*)0x3B)   // Port A Data Register
#define   DDRA	       (*(volatile u8*)0x3A)   // Port A Data Direction Register
#define   PINA	       (*(volatile u8*)0x39)   // Port A Input Pins Register

/*====PORTB====*/
#define   PORTB	       (*(volatile u8*)0x38)   // Port B Data Register
#define   DDRB	       (*(volatile u8*)0x37)   // Port B Data Direction Register
#define   PINB	       (*(volatile u8*)0x36)   // Port B Input Pins Register

/*====PORTC====*/
#define   PORTC	       (*(volatile u8*)0x35)   // Port C Data Register
#define   DDRC	       (*(volatile u8*)0x34)   // Port C Data Direction Register
#define   PINC	       (*(volatile u8*)0x33)   // Port C Input Pins Register

/*====PORTD====*/
#define   PORTD	       (*(volatile u8*)0x32)   // Port D Data Register
#define   DDRD	       (*(volatile u8*)0x31)   // Port D Data Direction Register
#define   PIND	       (*(volatile u8*)0x30)   // Port D Input Pins Register

// Timer/Counter Registers
#define   OCR0		   (*(volatile u8*)0x5C)   // Timer/Counter0 Output Compare Register
#define   TCCR0		   (*(volatile u8*)0x53)   // Timer/Counter0 Control Register
#define   TCNT0		   (*(volatile u8*)0x52)   // Timer/Counter0 Counter Register

#define   OCR1AH	   (*(volatile u8*)0x4B)   // Timer/Counter1 Output Compare Register High Byte
#define   OCR1AL	   (*(volatile u8*)0x4A)   // Timer/Counter1 Output Compare Register Low Byte
#define   OCR1A 	   (*(volatile u16*)0x4A)   // Timer/Counter1 Output Compare Register Low Byte

#define   OCR1BH	   (*(volatile u8*)0x49)   // Timer/Counter1 Output Compare Register High Byte
#define   OCR1BL	   (*(volatile u8*)0x48)   // Timer/Counter1 Output Compare Register Low Byte
#define   OCR1B	       (*(volatile u16*)0x48)   // Timer/Counter1 Output Compare Register Low Byte

#define   ICR1H		   (*(volatile u8*)0x47)   // Timer/Counter1 Input Capture Register High Byte
#define   ICR1L		   (*(volatile u8*)0x46)   // Timer/Counter1 Input Capture Register Low Byte
#define   ICR1		   (*(volatile u16*)0x46)   // Timer/Counter1 Input Capture Register Low Byte

#define   TCCR1A	   (*(volatile u8*)0x4F)   // Timer/Counter1 Control Register A
#define   TCCR1B	   (*(volatile u8*)0x4E)   // Timer/Counter1 Control Register B

#define   TCNT1H	   (*(volatile u8*)0x4D)   // Timer/Counter1 Counter Register High Byte
#define   TCNT1L	   (*(volatile u8*)0x4C)   // Timer/Counter1 Counter Register Low Byte
#define   TCNT1	       (*(volatile u16*)0x4C)   // Timer/Counter1 Counter Register Low Byte

#define   TCCR2		   (*(volatile u8*)0x45)   // Timer/Counter2 Control Register
#define   TCNT2		   (*(volatile u8*)0x44)   // Timer/Counter2 Counter Register
#define   OCR2		   (*(volatile u8*)0x43)   // Timer/Counter2 Output Compare Register



// USART Registers
#define   UDR		   (*(volatile u8*)0x2C)   // USART I/O Data Register
#define   UCSRA		   (*(volatile u8*)0x2B)   // USART Control and Status Register A
#define   UCSRB		   (*(volatile u8*)0x2A)   // USART Control and Status Register B
#define   UBRRL		   (*(volatile u8*)0x29)   // USART Baud Rate Register Low
#define   UBRRH		   (*(volatile u8*)0x40)   // USART Baud Rate Register Highs
#define   UCSRC		   (*(volatile u8*)0x40)   // USART Control and Status Register C

// ADC Registers
#define   ACSR		   (*(volatile u8*)0x28)   // Analog Comparator Control and Status Register
#define   ADMUX		   (*(volatile u8*)0x27)   // ADC Multiplexer Selection Register
#define   ADCSRA	   (*(volatile u8*)0x26)   // ADC Control and Status Register A
#define   ADCH		   (*(volatile u8*)0x25)   // ADC Data Register High Byte
#define   ADCL		   (*(volatile u8*)0x24)   // ADC Data Register Low Byte
#define   ADCDATA	   (*(volatile u16*)0x24)  // ADC Data Register

// I2C Registers
#define   TWDR		   (*(volatile u8*)0x23)   // Two-wire Serial Data Register
#define   TWAR		   (*(volatile u8*)0x22)   // Two-wire Serial Address Register
#define   TWSR		   (*(volatile u8*)0x21)   // Two-wire Serial Status Register
#define   TWBR		   (*(volatile u8*)0x20)   // Two-wire Serial Bit Rate Register
#define   TWCR		   (*(volatile u8*)0x56)   // Two-wire Serial Control Register

// SPI Registers
#define   SPDR         (*(volatile u8*)0x2F)   // SPI Data Register
#define   SPSR		   (*(volatile u8*)0x2E)   // SPI Status Register
#define   SPCR		   (*(volatile u8*)0x2D)   // SPI Control Registertatus Register C

// Watchdog Timer Registers
#define   WDTCR		   (*(volatile u8*)0x41)   // Watchdog Timer Control Register

// Timer/Counter Interrupts Registers
#define   TIMSK		   (*(volatile u8*)0x59)   // Timer/Counter Interrupt Mask Register
#define   TIFR		   (*(volatile u8*)0x58)   // Timer/Counter Interrupt Flag Register

// General Interrupts Registers
#define   GICR		   (*(volatile u8*)0x5B)   // General Interrupt Control Register
#define   GIFR		   (*(volatile u8*)0x5A)   // General Interrupt Flag Register

// EEPROM Registers
#define   EECR		   (*(volatile u8*)0x3C)   // EEPROM Control Register
#define   EEDR		   (*(volatile u8*)0x3D)   // EEPROM Data Register
#define   EEARL		   (*(volatile u8*)0x3E)   // EEPROM Address Register Low Byte
#define   EEARH		   (*(volatile u8*)0x3F)   // EEPROM Address Register High Byte

// Other Registers
#define   SREG         (*(volatile u8*)0x5F)   // Status Register
#define   SPH		   (*(volatile u8*)0x5E)   // Stack Pointer High Byte
#define   SPL		   (*(volatile u8*)0x5D)   // Stack Pointer Low Byte
#define   SPMCR		   (*(volatile u8*)0x57)   // Store Program Memory Control Register
#define   MCUCR		   (*(volatile u8*)0x55)   // MCU Control Register
#define   MCUCSR	   (*(volatile u8*)0x54)   // MCU Control and Status Register
#define   SFIOR		   (*(volatile u8*)0x50)   // Special Function IO Register
#define   OSCCAL       (*(volatile u8*)0x51)   // Oscillator Calibration Register
#define   OCDR         (*(volatile u8*)0x51)   // On-Chip Debug Register

#endif /* MEMMAP_H_ */
