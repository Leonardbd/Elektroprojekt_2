#include "gy273.hpp"


void GY273::init() {
    debug_println("GY273 init");
    i2c_init();     
    i2c_start();                    // Send start condition
    i2c_write((m_Address << 1) | 0); // Send device address with write bit
    i2c_write(0x02);                // Register Mode 
    i2c_write(0x00);                // Disable Idle Mode
    i2c_stop();                     // Send stop condition
}

void GY273::update() {

    i2c_start();                    // Send start condition
    i2c_write((m_Address << 1) | 0); // Send device address with write bit
    i2c_write(0x03);                // Send register address to read from (e.g. 0x00 for X-axis MSB)
    i2c_stop();                     // Send stop condition

    i2c_start();                    // Send start condition
    i2c_write((m_Address << 1) | 1); // Send device address with read bit
    uint8_t x_msb = i2c_read(1);    // Read X-axis MSB with ACK
    uint8_t x_lsb = i2c_read(1);    // Read X-axis LSB with ACK
    uint8_t y_msb = i2c_read(1);    // Read Y-axis MSB with ACK
    uint8_t y_lsb = i2c_read(1);    // Read Y-axis LSB with ACK
    uint8_t z_msb = i2c_read(1);    // Read Z-axis MSB with ACK
    uint8_t z_lsb = i2c_read(0);    // Read Z-axis LSB with NACK
    i2c_stop();                     // Send stop condition
    
    // Combine MSB and LSB readings to get X, Y, and Z values
    m_X = (x_msb << 8) | x_lsb;
    m_Y = (y_msb << 8) | y_lsb;
    m_Z = (z_msb << 8) | z_lsb;

    debug_println(m_X);
    /**
     * Enter sleep mode ???
     */
}
