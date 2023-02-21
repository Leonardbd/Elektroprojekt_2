#ifndef CORE_H
#define CORE_H


#include "gy273.hpp"
#include "adxl345.hpp"
#include "module.hpp"

#define MAX_MODULES 3

class Core {
public:
    ~Core();

    void init();
    void update();

private: 
   GY273    *m_GY273;
   ADXL345  *m_ADXL345;
};

#endif