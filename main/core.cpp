#include "core.hpp"

Core::~Core() {
    delete m_GY273;
    delete m_ADXL345;
}

void Core::init() {
    debug_println("~~~~ Core init ~~~~");
   
    #if ENABLE_GY273
        m_GY273 = new GY273();
        m_GY273->init();
    #endif

    #if ENABLE_ADXL345
        m_ADXL345 = new ADXL345();
        m_ADXL345->init();
    #endif
}

void Core::update() {
    debug_println("~~~~ Core Update ~~~~");
    
    #if ENABLE_GY273
        m_GY273->update();
    #endif

    #if ENABLE_ADXL345
        m_ADXL345->update();  
    #endif

}

