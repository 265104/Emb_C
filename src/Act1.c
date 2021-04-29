#include <avr/io.h>
#include<util/delay.h>


void port(){

    DDRB|=(1<<PB0); //set B0=1
    DDRD&=~(1<<PD0); //clear bit
    DDRD&=~(1<<PD1);
    PORTD|=(1<<PD0); //set bit
    PORTD|=(1<<PD1);



    }

