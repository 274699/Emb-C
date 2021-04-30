/**
 * @file activity4.h
 * @author Vishal Singh(vishalsingh47321@gmail.com)
 * @brief Function declaration
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED

void InitUART(uint16_t ubrr);

char UARTread();

void UARTwrite(char data);


#endif // ACTIVITY4_H_INCLUDED
