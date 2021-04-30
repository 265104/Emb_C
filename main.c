/*
 */

#include <avr/io.h>
#include<util/delay.h>
#include"Act1.h"
#include"Act2.h"
#include"Act3.h"
#include"Act4.h"

int main(void)
{
    port();
    InitADC();
    InitPWM();
    InitUSART(103);
    uint16_t temp;
    char temp_ch;

    while(1)
    {
        if((!(PIND&(1<<PD0)))&&(!(PIND&(1<<PD1)))) //switch press
        {
            PORTB|=(1<<PB0);
           _delay_ms(20);
        }
        else{
            PORTB&=~(1<<PB0);
        _delay_ms(20);
        }

        temp=ReadADC(0);
        _delay_ms(200);

        temp_ch=OutPWM(temp);
         USARTwrite(temp_ch);
    }

    return 0;
}
