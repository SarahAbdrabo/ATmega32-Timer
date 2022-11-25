/*includes*/

#include "Timer_Interface.h"
#include "Timer_Private.h"


#define NULL_PTR (void (*)(void))0


/******************************************************************TIMER 0***********************************************************************************/
void TIMER_voidTimer0Init(void)
{
    /* Select Prescaler in Reg TCCR0 */
    switch (TIMER_PS)
    {
    case TIMER_NO_CLK:  TIMER_TCCR0_REG = TIMER_NO_CLK; break;
    case TIMER_NO_PS:   TIMER_TCCR0_REG = TIMER_NO_PS; break;

    case TIMER_PS_8:    TIMER_TCCR0_REG = TIMER_PS_8; break;
    case TIMER_PS_32:   TIMER_TCCR0_REG = TIMER_PS_32; break;

    case TIMER_PS_64:   TIMER_TCCR0_REG = TIMER_PS_64; break;
    case TIMER_PS_128:  TIMER_TCCR0_REG = TIMER_PS_128; break;
    case TIMER_PS_256:  TIMER_TCCR0_REG = TIMER_PS_256; break;
    case TIMER_PS_1024: TIMER_TCCR0_REG = TIMER_PS_1024; break;
    
    default:    TIMER_TCCR0_REG = TIMER_NO_CLK; break;   //no choice of timer clock or ps, disable the timer
    }



    /* Select Mode
    WGM0 = 6 , WGM1 = 3  */
    switch (TIMER0_Mode)
    {
        case TIMER0_Noraml:
        {
            CLR_BIT(TIMER_TCCR0_REG,6);
	        CLR_BIT(TIMER_TCCR0_REG,3);
        }
        break;
        case TIMER0_CTC:
        {
            CLR_BIT(TIMER_TCCR0_REG,6);
            SET_BIT(TIMER_TCCR0_REG,3);
        }
        break;
        case TIMER0_PWM_fast:
        {
            SET_BIT(TIMER_TCCR0_REG,6);
	        SET_BIT(TIMER_TCCR0_REG,3);
        }
        break;
        case TIMER0_PWM_phase_correct:
        {
            CLR_BIT(TIMER_TCCR0_REG,6);
	        SET_BIT(TIMER_TCCR0_REG,3);
        }
        break;
    
    default: CLR_BIT(TIMER_TCCR0_REG,6); CLR_BIT(TIMER_TCCR0_REG,3); break;  //default : operate in normal mode.
    }

    /* SET the TCNT reg as 0 by default.*/
    TIMER_TCNT0_REG = 0x00;


	/*
    for PWM: 
    Select HW Action On OC0Pin => Non Inverting (COM0=0, COM1=1) or Inverting (11)
    COM0 = 4, COM1 = 5
    */
    switch (TIMER_OC_MODE)
    {
    case TIMER0_OC_NON_INV:
        CLR_BIT(TIMER_TCCR0_REG,4);
        SET_BIT(TIMER_TCCR0_REG,5);
        break;
    case TIMER0_OC_INVERT:
        SET_BIT(TIMER_TCCR0_REG,4);
        SET_BIT(TIMER_TCCR0_REG,5);
    default:
        break;
    }
}




/* function to set the OCR reg for TCT mode. */
void TIMER_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value){
    //check if the value is within 0 and 255
    if (Copy_u8OCR0Value > 255){
        break;
    }
    else {
        TIMER_OCR0_REG = Copy_u8OCR0Value;
    }
    
}


/*              needed for isr of tov               */

void (*TIMER0_CallBackPtr_OV)(void) = NULL_PTR ;

//the function called by the main. 
void TIMER_SetCallBack_OV( void(*Copy_ptrfn)(void) ){

	if (Copy_ptrfn != NULL_PTR){

		TIMER0_CallBackPtr_OV = Copy_ptrfn;
	}
}
void __vector_10(void){
    TIMER0_CallBackPtr_OV();
}

void (*TIMER0_CallBackPtr_OC)(void) = NULL_PTR ;

//the function called by the main. 
void TIMER_SetCallBack_OC( void(*Copy_ptrfn)(void) ){

	if (Copy_ptrfn != NULL_PTR){

		TIMER0_CallBackPtr_OC = Copy_ptrfn;
	}
}
void __vector_11(void){
    TIMER0_CallBackPtr_OC();
}





/******************************************************************TIMER 1***********************************************************************************/
void TIMER_voidTimer1Init(void){
 
{

    /*choice of WGM in the TCCR1A reg + TCCR1B regs, which dectiates the  TOP value from which we count */
    switch (TIMER1_MODE)
    {
    case TIMER1_NORMAL: 
        CLR_BIT(TIMER_TCCR1A_REG,1);
        CLR_BIT(TIMER_TCCR1A_REG,0);
        
        CLR_BIT(TIMER_TCCR1B_REG,4);
        CLR_BIT(TIMER_TCCR1B_REG,3);
        break;
/*etc for the 16 modes. */
    case TIMER1_PWM_FAST_OCR1:
        SET_BIT(TIMER_TCCR1A_REG,1);
        CLR_BIT(TIMER_TCCR1A_REG,0);

        SET_BIT(TIMER_TCCR1B_REG,4);
        SET_BIT(TIMER_TCCR1B_REG,3);
    
    default:
        break;
    }
    
    /*the choice of the operating mode using COM pins */

//	/* Select HW Action on OC1A pin => Non Inverting */
//	SET_BIT(TIMER_TCCR1A_REG,7);
//	CLR_BIT(TIMER_TCCR1A_REG,6);
//
//	/* Set Top Value in ICR1 */
//	TIMER_ICR1_REG = 19999;
//

//
//	/* Set Prescaler Value CLK/8 */
//	CLR_BIT(TIMER_u8_TCCR1B_REG,2);
//	SET_BIT(TIMER_u8_TCCR1B_REG,1);
//	CLR_BIT(TIMER_u8_TCCR1B_REG,0);



	/* Starts Timer1 at Prescaler 8 */
	CLR_BIT(TIMER_u8_TCCR1B_REG,2);
	SET_BIT(TIMER_u8_TCCR1B_REG,1);
	CLR_BIT(TIMER_u8_TCCR1B_REG,0);



}
