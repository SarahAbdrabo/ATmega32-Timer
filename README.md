# ATmega32-Timer

- Timer 0 example for AMIT Learing Oct 18 group. 
- Reqs : 1- PreScaler 1024 to achive 31 over flows
       2- using the internal clock with the prescaler. 
       3- blinking happens every 1 second. 



       the calcualtion for the prescaler 
       T(ov) = (PS * 256) / (Fclk)  = 32.7ms
       Ticks needed = (1000) / 32.7 =30.7 = 31. 

       fdgffd 
       



- the LED can be on any pin not the OC0 pin because this is not a PWM output
this is simply using the Timer as a counter. 
we choose :         LED on port C pin 3 


- since this is an ISR we will need to look up its place in the Vector table. 
TOV is #12 in VT = __vector_11 