#include "core.hpp"


Core::~Core() {
    delete m_GY273;
}

void Core::init() {
    m_GY273 = new GY273();
    m_GY273->init();
}

void Core::update() {
    m_GY273->update();
}

