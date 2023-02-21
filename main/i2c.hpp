#ifndef I2C_H
#define I2C_H

#include <avr/io.h>
#include <inttypes.h>

#ifndef F_CPU
    #define F_CPU 16000000UL    // 16 MHz
#endif

#ifndef SCL_CLOCK
    #define SCL_CLOCK 100000L   // 100 kHz
#endif

void i2c_init();
void i2c_start();
void i2c_stop();
void i2c_write(uint8_t data);
uint8_t i2c_read(bool ack);

#endif