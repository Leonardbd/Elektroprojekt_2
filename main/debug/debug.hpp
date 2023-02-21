#ifndef DEBUG_H
#define DEBUG_H

#include "../settings.hpp"
#include "Arduino.h"

#if DEBUG
  #define debug_init(x) Serial.begin(x); Serial.println("\n ---- Running Debug Mode (V3) ----");  while (!Serial) { delay(10); }
  #define debug_print(...) Serial.print(__VA_ARGS__)
  #define debug_println(...) Serial.println(__VA_ARGS__)
#else
  #define debug_init(x)
  #define debug_print(...) 
  #define debug_println(...) 
#endif

#endif

