/**
 * @file Utils_interrupt.h
 * @author Abdelrahman Ahmed Moussa (abdelrahman.ahmed0599@gmail.com  , https://www.linkedin.com/in/-abdelrahman-ahmed)
 * @brief  This file is a header file that contains the interrupt vectors and the assembly code for the AVR microcontroller
 * @version 0.1
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef UTILS_INTERRUPT_H_
#define UTILS_INTERRUPT_H_
  
/* ================================== vectors ================================== */
#define       INT0_VECT           __vector_1      // External Interrupt Request 0
#define       INT1_VECT           __vector_2	  // External Interrupt Request 1
#define       INT2_VECT           __vector_3	  // External Interrupt Request 2
#define       TIMER2_COMP_VECT    __vector_4	  // Timer/Counter2 Compare Match
#define       TIMER2_OVF_VECT     __vector_5	  // Timer/Counter2 Overflow
#define       TIMER1_CAPT_VECT    __vector_6	  // Timer/Counter1 Capture Event
#define       TIMER1_COMPA_VECT   __vector_7	  // Timer/Counter1 Compare Match A
#define       TIMER1_COMPB_VECT   __vector_8	  // Timer/Counter1 Compare Match B
#define       TIMER1_OVF_VECT     __vector_9	  // Timer/Counter1 Overflow
#define       TIMER0_COMP_VECT    __vector_10	  // Timer/Counter0 Compare Match
#define       TIMER0_OVF_VECT     __vector_11	  // Timer/Counter0 Overflow
#define       SPI_STC_VECT        __vector_12	  // Serial Transfer Complete
#define       USART_RXC_VECT      __vector_13	  // USART, Rx Complete
#define       USART_UDRE_VECT     __vector_14	  // USART Data Register Empty
#define       USART_TXC_VECT      __vector_15	  // USART, Tx Complete
#define       ADC_VECT            __vector_16	  // ADC Conversion Complete
#define       EE_RDY_VECT         __vector_17	  // EEPROM Ready
#define       ANA_COMP_VECT       __vector_18	  // Analog Comparator
#define       TWI_VECT            __vector_19	  // Two-wire Serial Interface
#define       SPM_RDY_VECT        __vector_20	  // Store Program Memory Ready
/* ==== bad interrupt ==== */
#define       BADISR_vect         __vector_default

/* ================================== assembly ================================== */
#define sei()   __asm__ __volatile__ ("sei"  ::)
#define cli()   __asm__ __volatile__ ("cli"  ::)
#define reti()  __asm__ __volatile__ ("reti" ::)
#define ret()   __asm__ __volatile__ ("ret"  ::)

/* ================================== Global interrupt enable/disable ================================== */
#define Global_Interrupt_Enable__asm()    __asm__ __volatile__ ("sei" ::)
#define Global_Interrupt_Disable__asm()   __asm__ __volatile__ ("cli" ::)

/* ================================== attributes ================================== */
/** \def ISR_BLOCK
    \ingroup avr_interrupts

    Identical to an ISR with no attributes specified. Global
    interrupts are initially disabled by the AVR hardware when
    entering the ISR, without the compiler modifying this state.

    Use this attribute in the attributes parameter of the ISR macro.
*/
#define ISR_BLOCK
/** \def ISR_NOBLOCK
    \ingroup avr_interrupts

    ISR runs with global interrupts initially enabled.  The interrupt
    enable flag is activated by the compiler as early as possible
    within the ISR to ensure minimal processing delay for nested
    interrupts.

    This may be used to create nested ISRs, however care should be
    taken to avoid stack overflows, or to avoid infinitely entering
    the ISR for those cases where the AVR hardware does not clear the
    respective interrupt flag before entering the ISR.

    Use this attribute in the attributes parameter of the ISR macro.
*/
#define ISR_NOBLOCK    __attribute__((interrupt))
/** \def ISR_NAKED
    \ingroup avr_interrupts

    ISR is created with no prologue or epilogue code. The user code is
    responsible for preservation of the machine state including the
    SREG register, as well as placing a reti() at the end of the
    interrupt routine.

    Use this attribute in the attributes parameter of the ISR macro.
*/
#define ISR_NAKED      __attribute__((naked))


/* ================================== ISR Macro Like Function ================================== */
/*
EX:
ISR(INT0_VECT,ISR_NOBLOCK)
{
	//ISR_CODE
}
// output of preprocessor: 
							void __vector_1 (void) __attribute__ ((signal)) __attribute__((interrupt));
							void __vector_1 (void)
							{
								//ISR_CODE
							}
*/
#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

#endif /* UTILS_INTERRUPT_H_ */