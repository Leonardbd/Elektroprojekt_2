#include "core.hpp"
#include "debug/debug.hpp"
#include "settings.hpp"

int main(void) {

    debug_init(BAUD);

    Core core;
    core.init();

    for (;;) {
        core.update();
    }

    return 0;
}