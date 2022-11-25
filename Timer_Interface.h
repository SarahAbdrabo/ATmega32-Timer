/*Inlcudes*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#ifndef _TIMER_INTERFACE_H
#define _TIMER_INTERFACE_H

/*
Functions for Timer 0: 
    A. Essenstial functions
     - init function (set prescaler - timer mode)
     - ctc mode set counter mode. 

     - interrupt sevice routine for overflow flag
     - interrupt for OC flag


    B. Supplemental functions
     - ctc mode delay
     - normal mode delay
     - ctc pwm function
*/
void TIMER_voidTimer0Init(void);
void TIMER_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);


/* 
Functions for Timer 1
    A. Essential funcntions
     -init function
     -ctc mode 

    B.Supplemental functions.
    - Servo motor set angle. 
*/
void TIMER_voidTimer1Init(void);
void TIMER_voidTimer1SetCompareMatchValue(u16 Copy_u16OCR1Value);



/*
Choose the desired mode for Timer 0 from 
    - Timer0_Noraml
    - Timer0_CTC
    - Timer0_PWM_fast
    - Timer0_PWM_phase_correct
*/
#define Timer0_Mode Timer0_Noraml

/*
Choose the desired mode for Timer 1 from 
    - Timer1_Noraml
    - Timer1_CTC
    - Timer1_PWM_fast
    - Timer1_PWM_phase_correct
*/
#define Timer1_Mode Timer1_Noraml

/* Prescaler choice */
#define     TIMER_PS     TIMER_PS_1024


/* Inverting or non inverting choice */
#define         TIMER_OC_MODE       TIMER0_OC_NONINV   

#endif