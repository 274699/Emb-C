/**
 * @file activity1.c
 * @author Vishal Singh(vishalsingh47321@gmail.com)
 * @brief This file contains the port information and behavior of ports
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
void setup_port(){
    DDRD|= (1<<PD0);
    DDRB|= (1<<PB3);
    DDRB&= ~(1<<PB0);
    DDRB&= ~(1<<PB2);


    PORTB&= ~(1<<PB3);
    PORTD&= ~(1<<PD0);
    PORTB|= (1<<PB0);
    PORTB|= (1<<PB2);
}
