
#include "core.hpp"
#include "settings.hpp"
#include "debug/debug.hpp"

#if DEBUG
    #include <Arduino.h>

    // Declared weak in Arduino.h to allow user redefinitions.
    int atexit(void (* /*func*/ )()) { return 0; }

    // Weak empty variant initialization function.
    // May be redefined by variant files.
    void initVariant() __attribute__((weak));
    void initVariant() { }
    void setupUSB() __attribute__((weak));
    void setupUSB() { }
#endif

int main(void) {

#if DEBUG
   	init();
	// initVariant();

    #if defined(USBCON)
        USBDevice.attach();
    #endif
#endif
	

    debug_init(BAUD);

    Core core;
    core.init();

    for (;;) {
        core.update();
    }

    return 0;
}