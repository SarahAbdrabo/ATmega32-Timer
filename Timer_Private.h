#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H



/* Regs used for Timer */
#define TIMER_TIMSK_REG           *((volatile u8*)0x59)
#define TIMER_TIFR_REG            *((volatile u8*)0x58)

/* TIMER 0 Registers */
#define TIMER_TCCR0_REG           *((volatile u8*)0x53)
#define TIMER_TCNT0_REG           *((volatile u8*)0x52)
#define TIMER_OCR0_REG            *((volatile u8*)0x5C)

/* TIMER  0 Modes */
 #define  TIMER0_NORMAL               0
 #define  TIMER0_CTC                  2
 #define  TIMER0_PWM_FAST             3
 #define  TIMER0_PWM_PC               1

/* Inverting or non inverting modes for OC0 pin */

#define TIMER0_OC_INVERT   9
#define TIMER0_OC_NON_INV   8



/* Timer 1 double Registers. */
#define TIMER_TCCR1A_REG          *((volatile u8*)0x4F)
#define TIMER_TCCR1B_REG          *((volatile u8*)0x4E)

#define TIMER_TCNT1H_REG          *((volatile u8*)0x4D)
#define TIMER_TCNT1L_REG          *((volatile u8*)0x4C)

#define TIMER_TCNT1_REG           *((volatile u16*)0x4C)

#define TIMER_OCR1AH_REG          *((volatile u8*)0x4B)
#define TIMER_OCR1AL_REG          *((volatile u8*)0x4A)

#define TIMER_OCR1A_REG           *((volatile u16*)0x4A)

#define TIMER_ICR1H_REG           *((volatile u8*)0x47)
#define TIMER_ICR1L_REG           *((volatile u8*)0x46)

#define TIMER_ICR1_REG            *((volatile u16*)0x46)

/* TIMER  1 Modes */
 #define  TIMER1_NORMAL               0
 #define  TIMER1_CTC                  2
 #define  TIMER1_PWM_FAST             3
 #define  TIMER1_PWM_PC               1



/* Prescaler choice in the clock select pins CS0,1,2*/
#define TIMER_NO_CLK        0
#define TIMER_NO_PS         1
#define TIMER_PS_8          2
#define TIMER_PS_32         3
#define TIMER_PS_64         4
#define TIMER_PS_128        5
#define TIMER_PS_256        6
#define TIMER_PS_1024       7   


#endif
