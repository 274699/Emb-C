/*
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    void setup();

    while(1){

    if(!(PINB&(1<<PB1))) // WHEN SEAT IS OCCUPIED
        {
        PORTB|= (1<<PB3); // PROMT PASSANGER TO TURN ON HEATER

        if(!(PINB&(1<<PB2))) //WHEN SEAT IS OCCUPIED AND HEATER IN ON
        {
            PORTB|= (1<<PB0); // ON WHEN HEATER IS TURNED ON
            PORTB&= ~(1<<PB3);// GOES OFF WHEN HEATER TURN ON
        }
        else{

        PORTB&= ~(1<<PB0);

    }
       while(!(PINB&(1<<PB2))){
        PORTB&= ~(1<<PB3);
       }
    }

    }
    return 0;
}
