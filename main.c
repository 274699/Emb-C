/**
 * @file main.c(Car seat heating application)
 * @author Vishal Singh(vishalsingh47321@gmail.com)
 * @brief Program for car seat heating application
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include <util/delay.h>

#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"
/**
 * @brief  Macros defined for switches and baud rate
 * 
 */

#define SEAT_SENSOR_SWITCH  (PINB&(1<<PB0))
#define HEATER_SWITCH  (PINB&(1<<PB2))
#define PRESSED  0
#define BAUD_RATE_9600_BPS  103


uint16_t temp=0;
char temp_data;
int main(void)
{
    setup_port();// This function will setup the ports for LEDs and switches- activity1.c
    timer1_setup();// Timer and counter register initialization- activity3.c
    InitializeADC();// Initializing ADC channel0- activity2.c
    InitUART(BAUD_RATE_9600_BPS);// Setting the baud rate for asynchronus UART communication- activity4.c


    while(1){

    if(SEAT_SENSOR_SWITCH == PRESSED)
        {
        PORTB|= (1<<PB3);
        _delay_ms(30);
            if(HEATER_SWITCH == PRESSED)
            {

                while(HEATER_SWITCH == PRESSED)
                {
                PORTD|= (1<<PD0);
                PORTB&= ~(1<<PB3);
                temp= ReadADC(0);  // storing adc value in a variable
                temp_data= Generate_PWM(temp); // Generating PWM signal according to ADC value
                UARTwrite(temp_data);  // Sending the value to the serial monitor via UART communication

                    }
            }
       else{

        PORTD&= ~(1<<PD0);
    }

    }
    else{
        PORTD&= ~(1<<PD0);
        PORTB&= ~(1<<PB3);
        OCR1A=0;
    }

    }
    return 0;
}

