/**
 * @file    main.c
 * @author  Group 02
 * @brief   IR robot 
 * @version 0.1
 * @date    2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 * Doc: https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
 */

#include <inttypes.h>

#define DDRD  *((volatile uint8_t*) 0x2A)   // Doc: § 13.4.8
#define PORTD *((volatile uint8_t*) 0x2B)   // Doc: § 13.4.9  
#define PIND  *((volatile uint8_t*) 0x29)   // Doc: § 13.4.10  

int main(void) {
    DDRD = 0b00110000;                      // Set 6 & 5 as Output
    for(;;) PORTD = PIND >> 0x02;           // Set IR value to sensors
}