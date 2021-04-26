/**
 * @file setup.c
 * @author vishal_274699 (you@domain.com)
 * @brief function defination for ports
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
void setup(){
DDRB|= (1<<PB0);// LED1 TURNS ON WHEN PASSANGER IS ON THE SEAT AND HEATER IS ON
    DDRB|= (1<<PB3); // LED2 INDICATE THE PASSANGER TO TURN ON HEATER
    DDRB&= ~(1<<PB1); //MAKING PB1 INPUT PIN  FOR BUTTONN SENSOR ON SEAT
    DDRB&= ~(1<<PB2); //MAKING PB2 INPUT PIN  FOR HEATER STATUS

    PORTB&= ~(1<<PB0);
    PORTB&= ~(1<<PB3);
    PORTB|= (1<<PB1); // SETTING PB1 HIGH TO AVOID FLOATING VOLTAGE
    PORTB|= (1<<PB2); //SETTING PB2 HIGH TO AVOID FLOATING VOLTAGE
}
