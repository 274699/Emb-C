/**
 * @file activity3.c
 * @author Vishal Singh(vishalsingh47321@gmail.com)
 * @brief This file initialize the timer and counter register and generate PWM signal
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief Initialize the timer and counter register
 * 
 */
void timer1_setup(){
   TCCR1A|=(1<<COM1A1)|(1<<WGM10)|(1<<WGM11);
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);
    DDRB|=(1<<PB1);
}
/**
 * @brief This function will generate the PWM signal and map the temperature value accordingly
 * 
 * @param ADC_val This is the converted analog value according to which PWM pulse is generated
 * @return char 
 */
  char Generate_PWM(uint16_t ADC_val ){

    char temperature;

    if((ADC_val>=0) && (ADC_val<=209)){

        OCR1A = 205; //20% duty cycle
        temperature = 20;
        _delay_ms(20);
    }
    else if((ADC_val>=210) && (ADC_val<=509)){

        OCR1A = 410; //40% duty cycle
        temperature = 25;
       _delay_ms(20);
    }
    else if((ADC_val>=510) && (ADC_val<=709)){

        OCR1A = 717;//70% duty cycle
         temperature = 29;
        _delay_ms(20);
    }
    else if((ADC_val>=710) && (ADC_val<=1024)){

        OCR1A = 973; //95% duty cycle
        temperature = 33;
        _delay_ms(20);
    }
    else{
        OCR1A = 0; //0% output
        temperature = 'NA';
    }
     return temperature;
}


