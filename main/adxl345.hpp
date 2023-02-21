#ifndef ADXL345_H
#define ADXL345_H

#include "module.hpp"
#include "debug/debug.hpp"

/**
 * @brief
 * 
 * @datasheet https://www.analog.com/media/en/technical-documentation/data-sheets/adxl345.pdf 
 * 
 */

class ADXL345: public Module {
public:
    inline ADXL345() : Module(0x53), m_X(0), m_Y(0), m_Z(0) {};
    void init()     override;
    void update()   override;
private:
    int16_t m_X, m_Y, m_Z;
};

#endif