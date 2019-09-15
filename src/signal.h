#ifndef SIGNAL_LIB
#define SIGNAL_LIB

#include "led.h"
#include "error.h"


enum Signal {SETUP_COMPLETE, IN_LOOP, DATA_COMPLETE, WRITE_COMPLETE};

void signal(Signal);

#endif //SIGNAL_LIB