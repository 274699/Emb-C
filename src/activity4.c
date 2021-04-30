/**
 * @file activity4.c
 * @author Vishal Singh(vishalsingh47321@gmail.com)
 * @brief this file will initialized the UART communication and write the data on serial monitor
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/io.h>
#include"activity4.h"
/**
 * @brief serial communication is setup
 * 
 * @param ubrr_value Baud rate value
 */

void InitUART(uint16_t ubrr_value){

    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&(0x00ff);
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);

    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}
/**
 * @brief write sthe data on serial monitor
 * 
 * @param data temeprature value sent by the adc channel
 */

void UARTwrite(char data)
{

    while(!(UCSR0A & (1<<UDRE0)));

    UDR0 = data;

}
