#include "i2c.hpp"

void i2c_init() {
    TWSR = 0x00;                                // Set prescaler
    TWBR = ((F_CPU/SCL_CLOCK)-16)/2;            // Set SCL frequency
}

void i2c_start() {
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);     // Send start condition
    while (!(TWCR & (1<<TWINT)));               // Wait for transmission to complete
}

void i2c_stop() {
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);     // Send stop condition
    while(!(TWCR & (1<<TWSTO)));                // Wait for transmission to complete
}

void i2c_write(uint8_t data) {
    TWDR = data;                                // Load data into data register
    TWCR = (1<<TWINT)|(1<<TWEN);                // Start transmission
    while (!(TWCR & (1<<TWINT)));               // Wait for transmission to complete
}

uint8_t i2c_read(bool ack) {
    TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);    // Start reception with or without ack
    while (!(TWCR & (1<<TWINT)));               // Wait for reception to complete
    return TWDR;                                // Return data received
}