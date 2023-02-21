#ifndef GY273_H
#define GY273_H

#include "module.hpp"
#include "debug/debug.hpp"

class GY273: public Module {
public:
    inline GY273() : Module(0x1E), m_X(0), m_Y(0), m_Z(0) {};
    void init()     override;
    void update()   override;
private:
    int16_t m_X, m_Y, m_Z;
};

#endif