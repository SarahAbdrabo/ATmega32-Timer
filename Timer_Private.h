#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define TIMER_TIMSK_REG           *((volatile u8*)0x59)
#define TIMER_TIFR_REG            *((volatile u8*)0x58)

/* TIMER 0 Registers */
#define TIMER_TCCR0_REG           *((volatile u8*)0x53)
#define TIMER_TCNT0_REG           *((volatile u8*)0x52)
#define TIMER_OCR0_REG            *((volatile u8*)0x5C)


/* Timer 1 double Registers. */
#define TIMER_TCCR1A_REG          *((volatile u8*)0x4F)
#define TIMER_TCCR1B_REG          *((volatile u8*)0x4E)

#define TIMER_TCNT1H_REG          *((volatile u8*)0x4D)
#define TIMER_TCNT1L_REG          *((volatile u8*)0x4C)

#define TIMER_TCNT1_REG          *((volatile u16*)0x4C)

#define TIMER_OCR1AH_REG          *((volatile u8*)0x4B)
#define TIMER_OCR1AL_REG          *((volatile u8*)0x4A)

#define TIMER_OCR1A_REG          *((volatile u16*)0x4A)

#define TIMER_ICR1H_REG           *((volatile u8*)0x47)
#define TIMER_ICR1L_REG           *((volatile u8*)0x46)

#define TIMER_ICR1_REG           *((volatile u16*)0x46)


#endif
