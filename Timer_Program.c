/*includes*/

#include "Timer_Interface.h"

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
    switch (Timer0_Mode)
    {
        case Timer0_Noraml:
        {
            CLR_BIT(TIMER_TCCR0_REG,6);
	        CLR_BIT(TIMER_TCCR0_REG,3);
        }
        break;
        case Timer0_CTC:
        {
            CLR_BIT(TIMER_TCCR0_REG,6);
            SET_BIT(TIMER_TCCR0_REG,3);
        }
        break;
        case Timer0_PWM_fast:
        {
            SET_BIT(TIMER_TCCR0_REG,6);
	        SET_BIT(TIMER_TCCR0_REG,3);
        }
        break;
        case Timer0_PWM_phase_correct:
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



/******************************************************************TIMER 1***********************************************************************************/
