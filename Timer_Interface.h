/*Inlcudes*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#ifndef _TIMER_INTERFACE_H
#define _TIMER_INTERFACE_H

/*
Functions for Timer 0: 
    A. Essenstial functions
    - init function 
     - ctc mode 

    B. Supplemental functions
     - delay function 
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


#endif