#include "signal.h"

//executes the led pattern depending on given signal
void signal(Signal sig) {
    switch (sig) {
        case SETUP_COMPLETE:
            // execute setup complete led pattern
            executePattern(12, 0b101010001010);
            break;
        case IN_LOOP:
            // execute in loop led pattern
            executePattern(6, 0b101000);
            break;
        case DATA_COMPLETE:
            // execute data complete led pattern
            executePattern(6, 0b111010);

            if(ERR_CODE==ERR_DATA_CORRUPT) 
                ERR_CODE = NO_ERROR;

            break;
        case WRITE_COMPLETE:
            // execute write complete led pattern
            executePattern(12, 0b100101010100);

            if(ERR_CODE == ERR_DATA_WRITE_FAILED)
                ERR_CODE = NO_ERROR;
                
            break;
        default:
            error(ERR_INVALID_SIGNAL);
            break;
    }
}