/*Spaghitti code to toggle a LED by the ISR of Normal mode Timer0 

Reqs : 1- PreScaler 1024 to achive 31 over flows
       2- using the internal clock with the prescaler. 
       3- blinking happens every 1 second. 



       the calcualtion for the prescaler 
       T(ov) = (PS * 256) / (Fclk)  = 32.7ms
       Ticks needed = (1000) / 32.7 =30.7 = 31. 



the LED can be on any pin not the OC0 pin because this is not a PWM output
this is simply using the Timer as a counter. 
we choose :         LED on port C pin 3 


since this is an ISR we will need to look up its place in the Vector table. 
TOV is #12 in VT = __vector_11

*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_Interface.h"   //to activate the GE 
#include "DIO_Interface.h"  //only for the LED output.

#define TCCR0     *((volatile u8*)0x53) 
#define TCNT0     *((volatile u8*)0x52) 
#define TIMSK    *((volatile u8*)0x59)   //sincec we will need the overflow flag. 



 volatile u8 count = 0; 

int main(void){

    //needed declerations. 
    TCCR = 0x05;            // the hexa value equivelent to 0b00000101;
    SET_BIT(TIMSK, 0);      //setting the bit to enable timer overflow. 

    GIE_voidEnable();
    DIO_voidSetPinVal(PORTC, PIN3, OUTPUT); //pin connected to LED

    while (1)
    {
        /* code */
    }

    return 0;
}



void Timer_Toggle_ISR(void)   //the isr function needs to: check on the numeber of overflows, reset it if reached and toggle the led. 
{
    count++;
    if (count == 31){
        DIO_voidTGLpin(PORTC, PIN3);
        count = 0;
    } 
}

void __vector_11(void) __attribute((signal));

void __vector_11(void)
{
    Timer_Toggle_ISR(); 
}