#ifndef MODULE_H
#define MODULE_H

#include "util/util.hpp"
#include "i2c.hpp"


class Module {
public:
    inline Module(u8 address) : m_Address(address) {};
    virtual void init()  ;
    virtual void update();
protected:
    u8 m_Address;
};

#endif